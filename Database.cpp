#include "Database.h"

/// \brief File structure is fixed
///
/// <number of tables>
/// <name_table0> <filename_table0>
/// <name_table1> <filename_table1>
/// ...............................
Database::Database(const std::string& fileName) {
    std::ifstream in(fileName, std::ios::in);

    if(!in) {
        return; //handle
    }

    unsigned int n;
    in >> n;

    for(unsigned int i = 0; i < n; ++i) {
        std::string tempName, tempFileName;
        in >> tempName >> tempFileName;

        this->tables.push_back(new Table(tempName, tempFileName));
        this->indexOf[tempName] = i;
    }
}

Database::~Database() {
    for(Table* &t : this->tables) {
        delete t;
    }

    this->tables.clear();
    this->indexOf.clear();
}

void Database::importT(const std::string& tName, const std::string& tFileName) {
    if(this->indexOf.find(tName) != this->indexOf.end()) {
        return; //handle
    }

    this->tables.push_back(new Table(tName, tFileName));
}

void Database::showT() const {
    std::cout << "Loaded table names:\n";

    for(const Table* t : this->tables) {
        std::cout << t->getName() << '\n';
    }
}

void Database::exportT(const std::string& tName, const std::string& fileName) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->saveToFile(fileName);
}

void innerJoin(const std::string&, const unsigned int&, 
               const std::string&, const unsigned int&);

void Database::printT(const std::string& tName) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->print();
}

void Database::describeT(const std::string& tName) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->describe();
}

void Database::selectT(const std::string& tName, const unsigned int& colIndex, const std::string& value) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->select(colIndex, value);
}

void Database::addColumnT(const std::string& tName, const std::string& colName, const std::string& colType) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->addColumn(colName, colType);
}

void Database::updateT(const std::string& tName, const unsigned int& colIndex, 
const std::string& value, const unsigned int& tColIndex, const std::string& tValue) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->update(colIndex, value, tColIndex, tValue);
}

void Database::delT(const std::string& tName, const unsigned int& colIndex, const std::string& value) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->del(colIndex, value);
}

void Database::insertT(const std::string& tName, const std::vector<std::string>& values) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->insert(values);
}

void Database::renameT(const std::string& tName, const std::string& newName) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return; //handle
    }

    if(this->indexOf.find(newName) != this->indexOf.end()) {
        return; //handle
    }

    unsigned int index = this->indexOf[tName];
    this->tables[index]->rename(newName);
}

unsigned int Database::countT(const std::string& tName, const unsigned int& colIndex, const std::string& value) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return 0; //handle
    }

    unsigned int index = this->indexOf[tName];
    return this->tables[index]->count(colIndex, value);
}

double Database::aggregateT(const std::string& tName, const unsigned int& colIndex, 
const std::string& value, const unsigned int& tColIndex, const std::string& tValue) {
    if(this->indexOf.find(tName) == this->indexOf.end()) {
        return 0; //handle
    }

    unsigned int index = this->indexOf[tName];
    return this->tables[index]->aggregate(colIndex, value, tColIndex, tValue);
}
