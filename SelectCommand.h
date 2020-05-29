#ifndef __SELECTCOMMAND_H_INCLUDED
#define __SELECTCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Select command class
class SelectCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        SelectCommand(const std::string&);
        ~SelectCommand();
};

#endif
