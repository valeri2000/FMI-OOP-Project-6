#ifndef __SAVEASCOMMAND_H_INCLUDED
#define __SAVEASCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Saveas command class
class SaveasCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        SaveasCommand(const std::string&);
        ~SaveasCommand();
};

#endif
