#include "PrintCommand.h"

void PrintCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    obj->printT(param);
}

PrintCommand::PrintCommand(const std::string& name) :
ICommand(name) {}

PrintCommand::~PrintCommand() {}
