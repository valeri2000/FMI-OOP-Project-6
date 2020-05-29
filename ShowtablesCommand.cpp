#include "ShowtablesCommand.h"

void ShowtablesCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    if(param.size() > 0) {
        ErrorState::setState(Flag::BAD_COMMAND);
        return;
    }

    obj->showT();
}

ShowtablesCommand::ShowtablesCommand(const std::string& name) :
ICommand(name) {}

ShowtablesCommand::~ShowtablesCommand() {}
