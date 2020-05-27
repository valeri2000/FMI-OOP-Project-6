#include "Table.h"
#include "ColumnFactory.h"
#include <fstream>
#include <iostream>

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
        return; //TODO
    }

    unsigned int cols, rows;
    in >> cols >> rows;
    this->countRows = rows;

    this->columns.resize(cols, nullptr);
    for(unsigned int currCol = 0; currCol < cols; ++currCol) {
        std::string colName, colType;
        in >> colName >> colType;

        IColumn* tryType = ColumnFactory::produce(colName, colType);
        if(tryType == nullptr) {
            return; //TODO
        }

        this->columns[currCol] = tryType;

        for(unsigned int currRow = 0; currRow < rows; ++currRow) {
            std::string cellValue;
            in >> cellValue;

            this->columns[currCol]->insertRowWith(cellValue);
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

void Table::print() const {
    std::cout << "Printing table " << this->name << '\n';
    for(unsigned int i = 0; i < this->countRows; ++i) {
        for(IColumn* currCol : this->columns) {
            std::cout << currCol->at(i) << ' ';
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

void Table::saveToFile(const std::string& newFile) const {
    std::ofstream out(newFile, std::ios::out | std::ios::trunc);

    out << (int)this->columns.size() << ' ' << this->countRows << '\n';

    for(IColumn* i : this->columns) {
        out << i->getName() << ' ' << i->getType() << '\n';

        for(unsigned j = 0; j < this->countRows; ++j) {
            out << i->at(j) << '\n';
        }
    }

    out.close();
}

void Table::select(const unsigned int& colIndex, const std::string& value) const {
    if(colIndex >= (int)this->columns.size()) {
        return; //todo
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
        return; //todo
    }

    this->columns.push_back(tryCol);

    for(unsigned int row = 0; row < this->countRows; ++row) {
        tryCol->insertRowWith("NULL");
    }
}

void Table::update(const unsigned int&, const std::string&, const unsigned int&, const std::string&) {

}

void Table::del(const unsigned int& colIndex, const std::string& value) {
    if(colIndex >= (int)this->columns.size()) {
        return;//todo
    }

    std::vector<unsigned int> indices = this->columns[colIndex]->getRowsIndicesWith(value);

    for(const unsigned int& rowIndex : indices) {
        for(IColumn* col : this->columns) {
            col->deleteRowByIndex(rowIndex);
        }
    } 

    this->countRows -= (int)indices.size();
}

void Table::insert(const std::vector<std::string>& values) {
    if((int)values.size() != (int)this->columns.size()) {
        return;//todo
    }

    this->countRows++;
    unsigned int index = 0;
    for(IColumn* col : this->columns) {
        col->insertRowWith(values[index++]); //isitcorrecttype
    }
}

void Table::rename(const std::string& newName) {
    this->name = newName;
}

unsigned int Table::count(const unsigned int&, const std::string&) {

}