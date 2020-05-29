#ifndef __COUNTCOMMAND_H_INCLUDED
#define __COUNTCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Count command class
class CountCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        CountCommand(const std::string&);
        ~CountCommand();
};

#endif
