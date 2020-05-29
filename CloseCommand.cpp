#include "CloseCommand.h"

void CloseCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first\n";
        return;
    }

    delete obj;
    obj = nullptr;
}

CloseCommand::CloseCommand(const std::string& name) :
ICommand(name) {}

CloseCommand::~CloseCommand() {}
