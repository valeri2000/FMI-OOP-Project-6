#ifndef __SHOWTABLES_H_INCLUDED
#define __SHOWTABLES_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Showtables command class
class ShowtablesCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        ShowtablesCommand(const std::string&);
        ~ShowtablesCommand();
};

#endif
