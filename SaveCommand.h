#ifndef __SAVECOMMAND_H_INCLUDED
#define __SAVECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Open command class
class SaveCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        SaveCommand(const std::string&);
        ~SaveCommand();
};

#endif
