#include "StringColumn.h"
#include "Parser.h"

std::string StringColumn::getType() const {
    return "string";
}

std::string StringColumn::at(const unsigned int& index) const {
    if(index >= data.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return "";
    }

    if(data[index].second == false) {
        return "NULL";
    }

    return data[index].first;
}

std::vector<unsigned int> 
StringColumn::getRowsIndicesWith(const std::string& value) const {
    std::vector<unsigned int> indices;

    if(Parser::isString(value) == false) {
        if(Parser::isNull(value) == true) {
            unsigned int index = 0;

            for(const std::pair<std::string, bool>& i : this->data) {
                if(i.second == false) {
                    indices.push_back(index);
                }

                index++;
            }
        }

        return indices;
    }

    unsigned int index = 0;
    for(const std::pair<std::string, bool>& i : this->data) {
        if(i.second == true && i.first == value) {
            indices.push_back(index);
        }

        index++;
    }

    return indices;
}

void StringColumn::updateRowByIndex(const unsigned int& index, const std::string& value) {
    if(index >= this->data.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    if(Parser::isString(value) == true) {
        this->data[index].first = value;
        this->data[index].second = true;
    } else if(Parser::isNull(value) == true) {
        this->data[index].second = false;
    } else {
        ErrorState::setState(Flag::BAD_TYPE);
    }
}

void StringColumn::deleteRowByIndex(const unsigned int& index) {
    unsigned int n = this->data.size();

    if(index >= n) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    for(unsigned int i = index + 1; i < n; ++i) {
        this->data[i - 1] = this->data[i];
    }
    this->data.pop_back();
}

void StringColumn::insertRowWith(const std::string& value) {
    if(Parser::isString(value) == true) {
        this->data.push_back(std::make_pair(value, true));
    } else if(Parser::isNull(value) == true) {
        this->data.push_back(std::make_pair("", false));
    }
}

StringColumn::StringColumn(const std::string& name) :
    IColumn(name) {}
