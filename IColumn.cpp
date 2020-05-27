#include "IColumn.h"

IColumn::IColumn(const std::string& name) :
    colName(name) {}

std::string IColumn::getName() const {
    return this->colName;
}

IColumn::~IColumn() {}
