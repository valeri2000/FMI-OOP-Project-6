#include "DoubleColumn.h"
#include "StringParser.h"
#include "Consts.h"
#include <cmath>

std::vector<unsigned int> 
DoubleColumn::getRowsIndicesWith(const std::string& value) const {
    std::vector<unsigned int> indices;

    std::pair<double, bool> parsed = StringParser::convertToDouble(value);
    if(parsed.second == false) {
        if(StringParser::isNull(value) == true) {
            unsigned int index = 0;

            for(const std::pair<double, bool>& i : this->data) {
                if(i.second == false) {
                    indices.push_back(index);
                }

                index++;
            }
        }

        return indices;
    }

    unsigned int index = 0;
    for(const std::pair<double, bool>& i : this->data) {
        if(i.second == true && fabs(i.first - parsed.first) < Consts::EPS) {
            indices.push_back(index);
        }

        index++;
    }

    return indices;
}

void DoubleColumn::updateRowByIndex(const unsigned int& index, const std::string& value) {
    if(index >= (int)this->data.size()) {
        return; //out of range
    }

    std::pair<double, bool> parsed = StringParser::convertToDouble(value);
    if(parsed.second == false) {
        if(StringParser::isNull(value) == false) {
            return; //incompatible value
        }
    }

    this->data[index] = parsed;
}

void DoubleColumn::deleteRowByIndex(const unsigned int& index) {
    int n = (int)this->data.size();

    if(index >= n) {
        return; //out of range
    }

    for(unsigned int i = index + 1; i < n; ++i) {
        this->data[i - 1] = this->data[i];
    }
    this->data.pop_back();
}

void DoubleColumn::insertRowWith(const std::string& value) {
    std::pair<double, bool> parsed = StringParser::convertToDouble(value);
    if(parsed.second == false) {
        if(StringParser::isNull(value) == false) {
            return; //incompatible type
        }
    }

    this->data.push_back(parsed);
}