#include "StringColumn.h"
#include "StringParser.h"

std::vector<unsigned int> 
StringColumn::getRowsIndicesWith(const std::string& value) const {
    std::vector<unsigned int> indices;

    if(StringParser::isString(value) == false) {
        if(StringParser::isNull(value) == true) {
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
    if(index >= (int)this->data.size()) {
        return; //out of range
    }

    if(StringParser::isString(value) == true) {
        this->data[index].first = value;
        this->data[index].second = true;
    } else if(StringParser::isNull(value) == true) {
        this->data[index].second = false;
    }
}

void StringColumn::deleteRowByIndex(const unsigned int& index) {
    int n = (int)this->data.size();

    if(index >= n) {
        return; //out of range
    }

    for(unsigned int i = index + 1; i < n; ++i) {
        this->data[i - 1] = this->data[i];
    }
    this->data.pop_back();
}

void StringColumn::insertRowWith(const std::string& value) {
    if(StringParser::isString(value) == true) {
        this->data.push_back(std::make_pair(value, true));
    } else if(StringParser::isNull(value) == true) {
        this->data.push_back(std::make_pair("", false));
    }
}

StringColumn::StringColumn(const std::string& name) :
    IColumn(name) {}
