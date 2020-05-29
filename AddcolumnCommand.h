#ifndef __ADDCOLUMNCOMMAND_H_INCLUDED
#define __ADDCOLUMNCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Addcolumn command class
class AddcolumnCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        AddcolumnCommand(const std::string&);
        ~AddcolumnCommand();
};

#endif
