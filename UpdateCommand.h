#ifndef __UPDATECOMMAND_H_INCLUDED
#define __UPDATECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Update command class
class UpdateCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        UpdateCommand(const std::string&);
        ~UpdateCommand();
};

#endif
