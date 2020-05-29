#include "SaveCommand.h"

void SaveCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    if(param.size() > 0) {
        std::cout << "Invalid command!\n";
        return;
    }
    
    obj->saveToInputFile();
}

SaveCommand::SaveCommand(const std::string& name) :
ICommand(name) {}

SaveCommand::~SaveCommand() {}
