#include "OpenCommand.h"

void OpenCommand::execute(const std::string& param, Database* & obj) {
    if(obj != nullptr) {
        std::cout << "Close first!\n";
        return;
    }

    obj = new Database(param);
}

OpenCommand::OpenCommand(const std::string& name) :
ICommand(name) {}

OpenCommand::~OpenCommand() {}
