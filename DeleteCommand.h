#ifndef __DELETECOMMAND_H_INCLUDED
#define __DELETECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Delete command class
class DeleteCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        DeleteCommand(const std::string&);
        ~DeleteCommand();
};

#endif
