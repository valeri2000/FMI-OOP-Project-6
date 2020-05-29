#ifndef __CLOSECOMMAND_H_INCLUDED
#define __CLOSECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Close command class
class CloseCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        CloseCommand(const std::string&);
        ~CloseCommand();
};

#endif
