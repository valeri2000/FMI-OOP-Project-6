#include "DoubleColumn.h"
#include "Parser.h"
#include <cmath>
#include <string>

const double EPS = 0.000000001;

std::string DoubleColumn::getType() const {
    return "double";
}

std::string DoubleColumn::at(const unsigned int& index) const {
    if(index >= data.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return "";
    }

    if(data[index].second == false) {
        return "NULL";
    }

    return std::to_string(data[index].first);
}

std::vector<unsigned int> 
DoubleColumn::getRowsIndicesWith(const std::string& value) const {
    std::vector<unsigned int> indices;

    std::pair<double, bool> parsed = Parser::convertToDouble(value);
    if(parsed.second == false) {
        if(Parser::isNull(value) == true) {
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
        if(i.second == true && fabs(i.first - parsed.first) < EPS) {
            indices.push_back(index);
        }

        index++;
    }

    return indices;
}

void DoubleColumn::updateRowByIndex(const unsigned int& index, const std::string& value) {
    if(index >= this->data.size()) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    std::pair<double, bool> parsed = Parser::convertToDouble(value);
    if(parsed.second == false) {
        if(Parser::isNull(value) == false) {
            ErrorState::setState(Flag::BAD_TYPE);
            return;
        }
    }

    this->data[index] = parsed;
}

void DoubleColumn::deleteRowByIndex(const unsigned int& index) {
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

void DoubleColumn::insertRowWith(const std::string& value) {
    std::pair<double, bool> parsed = Parser::convertToDouble(value);
    if(parsed.second == false) {
        if(Parser::isNull(value) == false) {
            ErrorState::setState(Flag::BAD_TYPE);
            return;
        }
    }

    this->data.push_back(parsed);
}

DoubleColumn::DoubleColumn(const std::string& name) :
    IColumn(name) {}
