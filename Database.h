#ifndef __DATABASE_H_INCLUDED
#define __DATABASE_H_INCLUDED

#include "Table.h"
#include <fstream>
#include <unordered_map>

/// \brief Database class which has tables
class Database {
    private:
        std::vector<Table*> tables; ///< vector of tables, which is the data in the database
        std::unordered_map<std::string, unsigned int> indexOf; ///< match table name to its index in the database 

    public:
        /// \brief Constructor for database
        /// \param 'const std::string' which is the file name
        Database(const std::string&);

        /// \brief Destructor which will delete the Table objects
        ~Database();

        /// \brief Import table
        /// \param first 'const std::string' which is the table name
        /// \param second 'const std::string' which is the file name
        void importT(const std::string&, const std::string&);

        /// \brief Show tables by names
        void showT() const;

        /// \brief Export table by name to file
        /// \param first 'const std::string' which is table name
        /// \param second 'const std::string' which is file name
        void exportT(const std::string&, const std::string&);

        /// \brief Inner join on two tables
        /// \param first 'const std::string' which is 1st table name
        /// \param second 'const unsigned int' which is column index of 1st table
        /// \param third 'const std::string' which is 2nd table name
        /// \param forth 'const unsigned int' which is column index of 2nd table
        void innerJoin(const std::string&, const unsigned int&, 
                       const std::string&, const unsigned int&);

    public:
        /// \brief Function which prints the table
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void printT(const std::string&);

        /// \brief Functions to describe column type names
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void describeT(const std::string&);

        /// \brief 'select' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void selectT(const std::string&, const unsigned int&, const std::string&);

        /// \brief 'addcolumn' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void addColumnT(const std::string&, const std::string&, const std::string&);

        /// \brief 'update' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void updateT(const std::string&, const unsigned int&, const std::string&, const unsigned int&, const std::string&);

        /// \brief 'delete' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void delT(const std::string&, const unsigned int&, const std::string&);

        /// \brief 'insert' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void insertT(const std::string&, const std::vector<std::string>&);

        /// \brief 'rename' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        void renameT(const std::string&, const std::string&);

        /// \brief 'count' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        unsigned int countT(const std::string&, const unsigned int&, const std::string&);

        /// \brief 'aggregate' function
        /// \param first 'const string' which is the name of the table
        ///
        /// (Expansion of table method)
        double aggregateT(const std::string&, const unsigned int&, const std::string&, const unsigned int&, const std::string&);
};

#endif
