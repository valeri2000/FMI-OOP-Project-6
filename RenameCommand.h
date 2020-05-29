#ifndef __RENAMECOMMAND_H_INCLUDED
#define __RENAMECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Rename command class
class RenameCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        RenameCommand(const std::string&);
        ~RenameCommand();
};

#endif
