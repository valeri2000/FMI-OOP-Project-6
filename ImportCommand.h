#ifndef __IMPORTCOMMAND_H_INCLUDED
#define __IMPORTCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Open command class
class ImportCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        ImportCommand(const std::string&);
        ~ImportCommand();
};

#endif
