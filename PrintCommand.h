#ifndef __PRINTCOMMAND_H_INCLUDED
#define __PRINTCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Print command class
class PrintCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        PrintCommand(const std::string&);
        ~PrintCommand();
};

#endif
