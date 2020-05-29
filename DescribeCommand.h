#ifndef __DESCRIBECOMMAND_H_INCLUDED
#define __DESCRIBECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Database.h"

/// \brief Describe command class
class DescribeCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Database* &) override;

    public:
        DescribeCommand(const std::string&);
        ~DescribeCommand();
};

#endif
