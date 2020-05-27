#ifndef __COLUMNFACTORY_H_INCLUDED
#define __COLUMNFACTORY_H_INCLUDED

#include "IColumn.h"

/// \brief Factory class to create columns
class ColumnFactory {
    public:
        /// \brief Static function which produces a column
        /// \param first 'const string' which is the column name
        /// \param second 'const string' which is the column type
        /// \return 'IColumn*' newly created column or nullptr
        static IColumn* produce(const std::string&, const std::string&);
};

#endif
