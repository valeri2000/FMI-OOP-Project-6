#include "DescribeCommand.h"

void DescribeCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    obj->describeT(param);
}

DescribeCommand::DescribeCommand(const std::string& name) :
ICommand(name) {}

DescribeCommand::~DescribeCommand() {}
