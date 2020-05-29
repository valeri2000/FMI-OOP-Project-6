#include "Database.h"
#include "ColumnFactory.h"
#include <cassert>

void Database::clearDatabase() {
    for(Table* &t : this->tables) {
        delete t;
    }

    this->tables.clear();
    this->indexOf.clear();
}

/// \brief File structure is fixed
///
/// <number of tables>
/// <name_table0> <filename_table0>
/// <name_table1> <filename_table1>
/// ...............................
Database::Database(const std::string& fileName) {
    std::ifstream in(fileName, std::ios::in);

    if(!in) {
        ErrorState::setState(Flag::BAD_FILE);
        return;
    }

    unsigned int n;
    in >> n;

    for(unsigned int i = 0; i < n; ++i) {
        std::string tempName, tempFileName;
        in >> tempName >> tempFileName;

        this->tables.push_back(new Table(tempName, tempFileName));

        if(ErrorState::getState() != Flag::GOOD) {
            return;
        }

        this->indexOf[tempName] = i;
    }
    
    this->inputFile = fileName;
}

Database::~Database() {
    this->clearDatabase();
}

void Database::saveToInputFile() {
    std::ofstream out(this->inputFile, std::ios::out | std::ios::trunc);

    out << this->tables.size() << '\n';

    for(unsigned int i = 0; i < this->tables.size(); ++i) {
        out << this->tables[i]->getName() << ' ';
        out << this->tables[i]->getFile() << '\n';
    }

    out.close();

    for(Table* t : this->tables) {
        t->saveToFile(t->getFile());
        assert(ErrorState::getState() == Flag::GOOD);
    }
}

void Database::saveToSpecificFile(const std::string& file) {
    std::ofstream out(file, std::ios::out | std::ios::trunc);

    if(!out) {
        ErrorState::setState(Flag::BAD_FILE);
        return;
    }

    out << this->tables.size() << '\n';

    for(unsigned int i = 0; i < this->tables.size(); ++i) {
        out << this->tables[i]->getName() << ' ';
        out << this->tables[i]->getFile() << '\n';
    }

    out.close();

    for(Table* t : this->tables) {
        t->saveToFile(t->getFile());
        assert(ErrorState::getState() == Flag::GOOD);
    }
}

void Database::importT(const std::string& tName, const std::string& tFileName) {
    if(this->indexOf.find(tName) != this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    Table* temp = new Table(tName, tFileName);

    if(ErrorState::getState() == Flag::GOOD) {
        this->tables.push_back(temp);
    }
}

void Database::showT() const {
    std::cout << "Loaded table names:\n";

    for(const Table* t : this->tables) {
        std::cout << t->getName() << '\n';
    }
}

void Database::exportT(const std::string& tName, const std::string& fileName) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->saveToFile(fileName);
}

void Database::innerJoin(const std::string& tName1, const unsigned int& colIndex1, 
const std::string& tName2, const unsigned int& colIndex2) {
    if(this->indexOf.find(tName1) == this->indexOf.end() ||
       this->indexOf.find(tName2) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index1 = this->indexOf[tName1],
                 index2 = this->indexOf[tName2];

    const IColumn* colTable1 = this->tables[index1]->columnAt(colIndex1);
    const IColumn* colTable2 = this->tables[index2]->columnAt(colIndex2);

    if(ErrorState::getState() != Flag::GOOD) {
        return;
    }

    if(colTable1->getType() !=
       colTable2->getType()) {
        ErrorState::setState(Flag::BAD_TYPE);
        return;
    }

    std::vector<IColumn*> newTable;
    newTable.push_back(ColumnFactory::produce("ijcol", colTable1->getType()));

    for(unsigned int j = 0; j < this->tables[index1]->getColumns(); ++j) {
        if(j == colIndex1) {
            continue;
        }

        newTable.push_back(ColumnFactory::produce(
            this->tables[index1]->columnAt(j)->getName(),
            this->tables[index1]->columnAt(j)->getType()
            )
        );
    }

    for(unsigned int j = 0; j < this->tables[index2]->getColumns(); ++j) {
        if(j == colIndex2) {
            continue;
        }

        newTable.push_back(ColumnFactory::produce(
            this->tables[index2]->columnAt(j)->getName(),
            this->tables[index2]->columnAt(j)->getType()
            )
        );
    }

    bool foundMatch = false;
    unsigned int newTableRows = 0;
    unsigned int allRows = this->tables[index1]->getRows();
    for(unsigned int currRow = 0; currRow < allRows; ++currRow) {
        std::vector<unsigned int> matchIndices = 
            colTable2->getRowsIndicesWith(colTable1->at(currRow));

        if(matchIndices.size() == 0) {
            continue;
        }

        foundMatch = true;
        for(const unsigned int& row : matchIndices) {
            // currRow table1 -> row table2
            newTableRows++;

            std::vector<std::string> valuesToAdd;
            valuesToAdd.push_back(colTable1->at(currRow));

            for(unsigned int j = 0; j < this->tables[index1]->getColumns(); ++j) {
                if(j == colIndex1) {
                    continue;
                }

                valuesToAdd.push_back(this->tables[index1]->columnAt(j)->at(currRow));
            }

            for(unsigned int j = 0; j < this->tables[index2]->getColumns(); ++j) {
                if(j == colIndex2) {
                    continue;
                }

                valuesToAdd.push_back(this->tables[index2]->columnAt(j)->at(row));
            }

            for(unsigned int index = 0; index < newTable.size(); ++index) {
                newTable[index]->insertRowWith(valuesToAdd[index]);
            }
        }  
    }

    if(!foundMatch) {
        std::cout << "Found no matches between rows!\n";
    } else {
        std::cout << "Found matches between rows! Inner Join completed!\n";
        
        for(unsigned int row = 0; row < newTableRows; ++row) {
            for(IColumn* i : newTable) {
                std::cout << i->at(row) << ' ';
            }

            std::cout << '\n';
        }
    }

    for(IColumn* &i : newTable) {
        delete i;
    }
    newTable.clear();
}

unsigned int Database::getTables() const {
    return this->tables.size();
}

void Database::printT(const std::string& tName) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->print();
}

void Database::describeT(const std::string& tName) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->describe();
}

void Database::selectT(const std::string& tName, const unsigned int& colIndex, const std::string& value) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->select(colIndex, value);
}

void Database::addColumnT(const std::string& tName, const std::string& colName, const std::string& colType) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->addColumn(colName, colType);
}

void Database::updateT(const std::string& tName, const unsigned int& colIndex, 
const std::string& value, const unsigned int& tColIndex, const std::string& tValue) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->update(colIndex, value, tColIndex, tValue);
}

void Database::delT(const std::string& tName, const unsigned int& colIndex, const std::string& value) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->del(colIndex, value);
}

void Database::insertT(const std::string& tName, const std::vector<std::string>& values) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->insert(values);
}

void Database::renameT(const std::string& tName, const std::string& newName) {
    if(this->indexOf.find(tName) == this->indexOf.end() ||
       this->indexOf.find(newName) != this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return;
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->rename(newName);

    this->indexOf.erase(tName);
    this->indexOf[newName] = index;
}

unsigned int Database::countT(const std::string& tName, const unsigned int& colIndex, const std::string& value) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return 0;
    }

    unsigned int index = this->indexOf[tName];
    return this->tables[index]->count(colIndex, value);
}

double Database::aggregateT(const std::string& tName, const unsigned int& colIndex, 
const std::string& value, const unsigned int& tColIndex, const std::string& tValue) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        ErrorState::setState(Flag::BAD_TABLE_NAME);
        return 0;
    }

    unsigned int index = this->indexOf[tName];
    return this->tables[index]->aggregate(colIndex, value, tColIndex, tValue);
}
