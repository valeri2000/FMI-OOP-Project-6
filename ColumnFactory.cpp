#include "ColumnFactory.h"

#include "IntColumn.h"
#include "DoubleColumn.h"
#include "StringColumn.h"

IColumn* ColumnFactory::produce(const std::string& colName, const std::string& colType) {
    if(colType == "int") {
        return new IntColumn(colName);
    }

    if(colType == "double") {
        return new DoubleColumn(colName);
    }

    if(colType == "string") {
        return new StringColumn(colName);
    }

    return nullptr;
}
