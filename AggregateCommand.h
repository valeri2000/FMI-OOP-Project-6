#ifndef __AGGREGATECOMMAND_H_INCLUDED
#define __AGGREGATECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Aggregate command class
class AggregateCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        AggregateCommand(const std::string&);
        ~AggregateCommand();
};

#endif
