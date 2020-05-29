#include "SaveasCommand.h"

void SaveasCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    obj->saveToSpecificFile(param);
}

SaveasCommand::SaveasCommand(const std::string& name) :
ICommand(name) {}

SaveasCommand::~SaveasCommand() {}
