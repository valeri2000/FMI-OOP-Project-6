#ifndef __INSERTCOMMAND_H_INCLUDED
#define __INSERTCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Insert command class
class InsertCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        InsertCommand(const std::string&);
        ~InsertCommand();
};

#endif
