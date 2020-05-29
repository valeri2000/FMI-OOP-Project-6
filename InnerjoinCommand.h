#ifndef __INNERJOINCOMMAND_H_INCLUDED
#define __INNERJOINCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Inner join command class
class InnerjoinCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        InnerjoinCommand(const std::string&);
        ~InnerjoinCommand();
};

#endif
