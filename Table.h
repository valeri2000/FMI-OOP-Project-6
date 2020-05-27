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

        /// \brief Getter for table name
        /// \return 'string' which is the name of the table
        std::string getName() const;

        /// \brief Getter for the file name
        /// \return 'string' which is the file name
        std::string getFile() const;
        
        /// \brief Function which prints the table
        void print() const;

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

        //aggregate

};

#endif
