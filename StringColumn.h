#ifndef __STRINGCOLUMN_H_INCLUDED
#define __STRINGCOLUMN_H_INCLUDED

#include "IColumn.h"

/// \brief Class for string column type
class StringColumn : public IColumn {
    public:
        virtual std::string 
            getType() const override;
        virtual std::string 
            at(const unsigned int&) const override;
        virtual std::vector<unsigned int> 
            getRowsIndicesWith(const std::string&) const override;
        virtual void 
            updateRowByIndex(const unsigned int&, const std::string&) override;
        virtual void
            deleteRowByIndex(const unsigned int&) override;
        virtual void
            insertRowWith(const std::string&) override;

        /// \brief Constructor accepting column name as parameter
        StringColumn(const std::string&);
        
    private:
        std::vector< std::pair<std::string, bool> > 
            data; ///< field for storing row values\n
                  /// which are pairs having a boolean\n
                  /// as second value which is 'false' if\n
                  /// the cell is 'NULL'
};

#endif
