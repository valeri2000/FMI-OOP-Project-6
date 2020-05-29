#include "PrintCommand.h"

void PrintCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    obj->printT(param);
}

PrintCommand::PrintCommand(const std::string& name) :
ICommand(name) {}

PrintCommand::~PrintCommand() {}
