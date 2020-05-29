#include "ShowtablesCommand.h"

void ShowtablesCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    if((int)param.size() > 0) {
        std::cout << "Invalid command!\n";
        return;
    }

    obj->showT();
}

ShowtablesCommand::ShowtablesCommand(const std::string& name) :
ICommand(name) {}

ShowtablesCommand::~ShowtablesCommand() {}
