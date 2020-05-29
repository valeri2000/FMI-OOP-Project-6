#include "DescribeCommand.h"

void DescribeCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    obj->describeT(param);
}

DescribeCommand::DescribeCommand(const std::string& name) :
ICommand(name) {}

DescribeCommand::~DescribeCommand() {}
