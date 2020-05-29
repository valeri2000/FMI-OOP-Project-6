#include "IntColumn.h"
#include "Parser.h"
#include <string>

std::string IntColumn::getType() const {
    return "int";
}

std::string IntColumn::at(const unsigned int& index) const {
    if(index >= data.size()) {
        return ""; //todo
    }

    if(data[index].second == false) {
        return "NULL";
    }

    return std::to_string(data[index].first);
}

std::vector<unsigned int> 
IntColumn::getRowsIndicesWith(const std::string& value) const {
    std::vector<unsigned int> indices;

    std::pair<int, bool> parsed = Parser::convertToInt(value);
    if(parsed.second == false) {
        if(Parser::isNull(value) == true) {
            unsigned int index = 0;

            for(const std::pair<int, bool>& i : this->data) {
                if(i.second == false) {
                    indices.push_back(index);
                }

                index++;
            }
        }

        return indices;
    }

    unsigned int index = 0;
    for(const std::pair<int, bool>& i : this->data) {
        if(i.second == true && i.first == parsed.first) {
            indices.push_back(index);
        }

        index++;
    }

    return indices;
}

void IntColumn::updateRowByIndex(const unsigned int& index, const std::string& value) {
    if(index >= this->data.size()) {
        return; //out of range
    }

    std::pair<int, bool> parsed = Parser::convertToInt(value);
    if(parsed.second == false) {
        if(Parser::isNull(value) == false) {
            return; //incompatible value
        }
    }

    this->data[index] = parsed;
}

void IntColumn::deleteRowByIndex(const unsigned int& index) {
    unsigned int n = this->data.size();

    if(index >= n) {
        return; //out of range
    }

    for(unsigned int i = index + 1; i < n; ++i) {
        this->data[i - 1] = this->data[i];
    }
    this->data.pop_back();
}

void IntColumn::insertRowWith(const std::string& value) {
    std::pair<int, bool> parsed = Parser::convertToInt(value);
    if(parsed.second == false) {
        if(Parser::isNull(value) == false) {
            ErrorState::setState(Flag::BAD_TYPE);
            return;
        }
    }

    this->data.push_back(parsed);
}

IntColumn::IntColumn(const std::string& name) :
    IColumn(name) {}
