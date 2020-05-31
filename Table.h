#ifndef __TABLE_H_INCLUDED
#define __TABLE_H_INCLUDED

#include "IColumn.h"

/// \brief Table class
class Table {
    private:
        std::string name; ///< name of the table
        std::string file; ///< file in which the table is saved
        std::vector<IColumn*> columns; ///< columns in the table constructing the rows
        unsigned int countRows;

    public:
        /// \brief Constructor with 2 parameters
        /// \param first 'string' which is the name of the table
        /// \param second 'string' which is the file from which the table is loaded
        Table(const std::string&, const std::string&);

        /// \brief Destructor as we have dynamic memory
        ~Table();

        /// \brief Disable copy constructor
        Table(const Table&) = delete;

        /// \brief Disable operator=
        Table& operator = (const Table&) = delete;

        /// \brief Getter for table name
        /// \return 'string' which is the name of the table
        std::string getName() const;

        /// \brief Getter for the file name
        /// \return 'string' which is the file name
        std::string getFile() const;

        /// \brief Getter for number of rows
        /// \return 'unsigned int' which is the desired number
        unsigned int getRows() const;

        /// \brief Getter for number of columns
        /// \return 'unsigned int' which is the desired number
        unsigned int getColumns() const;
        
        /// \brief Getter for specific column by index
        /// \param 'const unsigned int' which is the column index
        /// \return 'const IColumn*' which is const pointer to the desired column
        const IColumn* columnAt(const unsigned int&) const;

        /// \brief Function which prints the table
        void print() const;

        /// \brief Functions to describe column type names
        void describe() const;

        /// \brief Function which saves the table to specific file
        /// \param 'string' which is the file name
        void saveToFile(const std::string&) const;

        /// \brief 'select' function
        /// \param first 'const unsigned int' which is column index
        /// \param second 'const string' which is the value to be searched for
        void select(const unsigned int&, const std::string&) const;

        /// \brief 'addcolumn' function
        /// \param first 'const string' which is the new column name
        /// \param second 'const string' which is the new column type
        void addColumn(const std::string&, const std::string&);

        /// \brief 'update' function
        /// \param first 'const unsigned int' which is the asked column index
        /// \param second 'const string' which is the asked value in row
        /// \param third 'const unsigned int' which is the target column index
        /// \param forth 'const string' which is the value to be assigned to corresponding cells
        void update(const unsigned int&, const std::string&, const unsigned int&, const std::string&);

        /// \brief 'delete' function
        /// \param first 'const unsigned int' which is the desired column index
        /// \param second 'const string' which is the value to be searched for
        void del(const unsigned int&, const std::string&);

        /// \brief 'insert' function
        /// \param 'const vector<string>' which contains the values to be added to the columns
        void insert(const std::vector<std::string>&);

        /// \brief 'rename' function
        /// \param 'const string' which is the new name for the table
        void rename(const std::string&);

        /// \brief 'count' function
        /// \param first 'const unsigned int' which is the asked column index
        /// \param second 'const string' which is the searched value
        /// \return 'unsigned int' which is the number of those cells
        unsigned int count(const unsigned int&, const std::string&);

        /// \brief 'aggregate' function
        /// \param first 'const unsigned int' which is the asked column index
        /// \param second 'const string' which is the value to be searched for
        /// \param third 'const unsigned int' which is the target column index
        /// \param forth 'const string' which is the operation(sum, product, maximum, minimum)
        /// \return 'double' which is the result number after performing the operation
        double aggregate(const unsigned int&, const std::string&, const unsigned int&, const std::string&);
};

#endif
