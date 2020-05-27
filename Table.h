#ifndef __TABLE_H_INCLUDED
#define __TABLE_H_INCLUDED

#include "IColumn.h"

class Table {
    private:
        std::string name;
        std::string file;
        std::vector<IColumn*> columns;

    public:
        Table(const std::string&, const std::string&);
        ~Table();

        std::string getName() const;
        std::string getFilePath() const;
        
        void print() const;
        void saveToFile(const std::string&) const;

        void select(const unsigned int&, const std::string&) const;
        void addColumn(const std::string&, const std::string&); //name, type
        void update(const unsigned int&, const std::string&, const unsigned int&, const std::string&);
        void del(const unsigned int&, const std::string&);
        void insert(const std::vector<std::string>&);
        //innerjoin
        void rename(const std::string&);
        unsigned int count(const unsigned int&, const std::string&);
        //aggregate

};

#endif
