#include "IntColumn.h"
#include "StringParser.h"

std::vector<unsigned int> 
IntColumn::getRowsIndicesWith(const std::string& value) const {
    std::vector<unsigned int> indices;

    std::pair<int, bool> parsed = StringParser::convertToInt(value);
    if(parsed.second == false) {
        if(StringParser::isNull(value) == true) {
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
    if(index >= (int)this->data.size()) {
        return; //out of range
    }

    std::pair<int, bool> parsed = StringParser::convertToInt(value);
    if(parsed.second == false) {
        if(StringParser::isNull(value) == false) {
            return; //incompatible value
        }
    }

    this->data[index] = parsed;
}

void IntColumn::deleteRowByIndex(const unsigned int& index) {
    int n = (int)this->data.size();

    if(index >= n) {
        return; //out of range
    }

    for(unsigned int i = index + 1; i < n; ++i) {
        this->data[i - 1] = this->data[i];
    }
    this->data.pop_back();
}

void IntColumn::insertRowWith(const std::string& value) {
    std::pair<int, bool> parsed = StringParser::convertToInt(value);
    if(parsed.second == false) {
        if(StringParser::isNull(value) == false) {
            return; //incompatible type
        }
    }

    this->data.push_back(parsed);
}
