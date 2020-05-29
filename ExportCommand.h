#ifndef __EXPORTCOMMAND_H_INCLUDED
#define __EXPORTCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Export command class
class ExportCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        ExportCommand(const std::string&);
        ~ExportCommand();
};

#endif
