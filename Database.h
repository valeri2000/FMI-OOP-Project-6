#ifndef __DATABASE_H_INCLUDED
#define __DATABASE_H_INCLUDED

#include "Table.h"
#include <fstream>

class Database {
    private:
        std::vector<Table*> tables;

    public:
        Database(std::ifstream&);
        ~Database();

        void importTable(const std::string&);
        void showTables() const;
        void exportTable(const std::string&, const std::string&);
        void innerJoin(const std::string&, const unsigned int&, 
                       const std::string&, const unsigned int&);
};

#endif
