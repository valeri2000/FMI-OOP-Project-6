#include "Table.h"
#include "ColumnFactory.h"
#include "Parser.h"
#include <fstream>
#include <iostream>
#include <cassert>

/// \brief File data structure is fixed
///
/// <cols> <rows>\n
/// <col0 name>\n
/// <col0 type>\n
/// <col0row0>\n
/// <col0row1>\n
/// .........\n
/// <col0rowrows-1>\n
/// <col1 name>\n
/// <col1 type>\n
/// <col1row0>\n
/// ..........
Table::Table(const std::string& newName, const std::string& newFile) :
name(newName), file(newFile) {
    std::ifstream in(file, std::ios::in);

    if(!in) {
        ErrorState::setState(Flag::BAD_FILE);
        in.close();
        return;
    }

    unsigned int cols, rows;
    in >> cols >> rows;
    this->countRows = rows;

    this->columns.resize(cols, nullptr);
    for(unsigned int currCol = 0; currCol < cols; ++currCol) {
        std::string colName, colType;
        in >> colName >> colType;
        in.ignore(1024, '\n');

        IColumn* tryType = ColumnFactory::produce(colName, colType);
        if(tryType == nullptr) {
            ErrorState::setState(Flag::BAD_TYPE);
            in.close();
            return;
        }

        this->columns[currCol] = tryType;

        for(unsigned int currRow = 0; currRow < rows; ++currRow) {
            std::string cellValue;
            std::getline(in, cellValue);

            this->columns[currCol]->insertRowWith(cellValue);
            if(ErrorState::getState() != Flag::GOOD) {
                in.close();
                return;
            }
        }
    }

    in.close();
}

Table::~Table() {
    this->name = this->file = "";

    for(IColumn* &i : this->columns) {
        delete i;
    }
    this->columns.clear();
}

std::string Table::getName() const {
    return this->name;
}

std::string Table::getFile() const {
    return this->file;
}

unsigned int Table::getRows() const {
    return this->countRows;
}

unsigned int Table::getColumns() const {
    return this->columns.size();
}

const IColumn* Table::columnAt(const unsigned int& colIndex) const {
    if(colIndex >= this->columns.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return nullptr;
    }

    return this->columns[colIndex];
}

void Table::print() const {
    std::cout << "Printing table " << this->name << '\n';
    
    for(IColumn* currCol : this->columns) {
        std::cout << currCol->getName() << ' ';
    }
    std::cout << '\n';

    for(unsigned int i = 0; i < this->countRows; ++i) {
        for(IColumn* currCol : this->columns) {
            std::cout << currCol->at(i) << ' ';
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

void Table::describe() const {
    for(IColumn* currCol : this->columns) {
        std::cout << currCol->getType() << ' ';
    }
    
    std::cout << '\n';
}

void Table::saveToFile(const std::string& newFile) const {
    std::ofstream out(newFile, std::ios::out | std::ios::trunc);

    if(!out) {
        ErrorState::setState(Flag::BAD_FILE);
        out.close();

        return;
    }

    out << this->columns.size() << ' ' << this->countRows << '\n';

    for(IColumn* i : this->columns) {
        out << i->getName() << ' ' << i->getType() << '\n';

        for(unsigned j = 0; j < this->countRows; ++j) {
            out << i->at(j) << '\n';
        }
    }

    out.close();
}

void Table::select(const unsigned int& colIndex, const std::string& value) const {
    if(colIndex >= this->columns.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    std::vector<unsigned int> indices = this->columns[colIndex]->getRowsIndicesWith(value);

    for(const unsigned int& index : indices) {
        for(IColumn* col : this->columns) {
            std::cout << col->at(index) << ' ';
        }

        std::cout << '\n';
    }
}

void Table::addColumn(const std::string& colName, const std::string& colType) {
    IColumn* tryCol = ColumnFactory::produce(colName, colType);

    if(tryCol == nullptr) {
        ErrorState::setState(Flag::BAD_TYPE);
        return;
    }

    this->columns.push_back(tryCol);

    for(unsigned int row = 0; row < this->countRows; ++row) {
        tryCol->insertRowWith("NULL");
    }
}

void Table::update(const unsigned int& colIndex, const std::string& value, 
const unsigned int& tcolIndex, const std::string& tvalue) {
    if(colIndex >= this->columns.size() ||
       tcolIndex >= this->columns.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    std::vector<unsigned int> indices = this->columns[colIndex]->getRowsIndicesWith(value);

    for(const unsigned int& currRow : indices) {
        this->columns[tcolIndex]->updateRowByIndex(currRow, tvalue);

        if(ErrorState::getState() != Flag::GOOD) {
            break;
        }
    }
}

void Table::del(const unsigned int& colIndex, const std::string& value) {
    if(colIndex >= this->columns.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    std::vector<unsigned int> indices = this->columns[colIndex]->getRowsIndicesWith(value);

    unsigned int offset = 0;
    for(unsigned int& rowIndex : indices) {
        rowIndex -= offset;

        for(IColumn* col : this->columns) {
            col->deleteRowByIndex(rowIndex);

            if(ErrorState::getState() != Flag::GOOD) {
                assert(true == false);
            }
        }

        offset++;
    } 

    this->countRows -= indices.size();
}

void Table::insert(const std::vector<std::string>& values) {
    if(values.size() != this->columns.size()) {
        ErrorState::setState(Flag::BAD_COMMAND);
        return;
    }

    unsigned int index = 0;
    bool typeMatch = true;
    for(IColumn* col : this->columns) {
        std::string currType = col->getType();

        if(currType == "string") {
            if(Parser::isString(values[index]) == false &&
                Parser::isNull(values[index]) == false) {
                typeMatch = false;
                break;
            }
        } 
        else if(currType == "int") {
            if(Parser::convertToInt(values[index]).second == false &&
                Parser::isNull(values[index]) == false) {
                typeMatch = false;
                break;
            }
        } 
        else if(currType == "double") {
            if(Parser::convertToDouble(values[index]).second == false &&
                Parser::isNull(values[index]) == false) {
                typeMatch = false;
                break;
            }
        } 
        else {
            assert(true == false);
        }

        index++;
    }

    if(!typeMatch) {
        ErrorState::setState(Flag::BAD_TYPE);
        return;
    }

    this->countRows++;
    index = 0;
    for(IColumn* col : this->columns) {
        col->insertRowWith(values[index++]);

        if(ErrorState::getState() != Flag::GOOD) {
            assert(true == false);
        }
    }
}

void Table::rename(const std::string& newName) {
    this->name = newName;
}

unsigned int Table::count(const unsigned int& colIndex, const std::string& value) {
    if(colIndex >= this->columns.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return 0;
    }

    std::vector<unsigned int> indices = this->columns[colIndex]->getRowsIndicesWith(value);

    return indices.size();
}

double Table::aggregate(const unsigned int& colIndex, const std::string& value, 
const unsigned int& tcolIndex, const std::string& oper) {
    if(colIndex >= this->columns.size() ||
       tcolIndex >= this->columns.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return 0;
    }

    std::string tColType = this->columns[tcolIndex]->getType();
    if(tColType != "int" && tColType != "double") {
        ErrorState::setState(Flag::BAD_TYPE);
        return 0;
    }

    std::vector<unsigned int> indices = this->columns[colIndex]->getRowsIndicesWith(value);
    std::vector<double> tempValues;

    for(const unsigned int& currRow : indices) {
        double currValue = Parser::convertToDouble(
            this->columns[tcolIndex]->at(currRow)
        ).first;

        if(ErrorState::getState() != Flag::GOOD) {
            assert(true == false);
        }

        tempValues.push_back(currValue);
    }

    double res = 0;
    if(oper == "sum") {
        res = 0;

        for(const double& currValue : tempValues) {
            res += currValue;
        }
    } else if(oper == "product") {
        res = 1;

        for(const double& currValue : tempValues) {
            res *= currValue;
        }
    } else if(oper == "maximum") {
        res = -1e9;

        for(const double& currValue : tempValues) {
            res = std::max(res, currValue);
        }
    } else if(oper == "minimum") {
        res = 1e9;

        for(const double& currValue : tempValues) {
            res = std::min(res, currValue);
        }
    } else {
        ErrorState::setState(Flag::BAD_OPERATION);
    }

    return res;
}
