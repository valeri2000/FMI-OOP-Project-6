#ifndef __ICOLUMN_H_INCLUDED
#define __ICOLUMN_H_INCLUDED

#include <vector>
#include <iostream>

/// \brief Abstract class for all columns.
/// 
/// Different column types will have it as a base class.\n
/// All public pure virtual methods in it will be implemented\n
/// in derived classes.
class IColumn {
    private:
        std::string colName; ///< name of the column

    public:
        /// \brief Constructor acception column name as parameter
        IColumn(const std::string&);

        /// \brief Getter for column name
        /// \return column name
        std::string getName() const;

        /// \brief Virtual destructor for deleting objects with no leak
        virtual ~IColumn();

        /// \brief Pure virtual function for determining column type
        /// \return column type as text
        virtual std::string getType() const = 0;

        /// \brief Pure virtual function for get values at index
        /// \param 'const unsigned int' which is the desired index
        /// \return 'const string&' which is the value converted to text
        virtual std::string 
            at(const unsigned int&) const = 0;
        
        /// \brief Pure virtual function to get row indices which have specific value.
        /// \param parameter 'const string' which is the desired value
        /// \return a vector of all row indices
        virtual std::vector<unsigned int> 
            getRowsIndicesWith(const std::string&) const = 0;

        /// \brief Pure virtual function to update row index with specific value.
        /// \param first 'const unsigned int' which is the desired index
        /// \param second 'const string' which is the new value
        virtual void 
            updateRowByIndex(const unsigned int&, const std::string&) = 0;

        /// \brief Pure virtual function to delete row by index.
        /// \param parameter 'const unsigned int' which is the desired index
        virtual void
            deleteRowByIndex(const unsigned int&) = 0;

        /// \brief Pure virtual function to insert a row at end with value.
        /// \param parameter 'const string' which is the desired value
        virtual void
            insertRowWith(const std::string&) = 0;
};

#endif
