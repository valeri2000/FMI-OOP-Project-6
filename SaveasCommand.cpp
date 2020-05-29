#include "SaveasCommand.h"

void SaveasCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    obj->saveToSpecificFile(param);
}

SaveasCommand::SaveasCommand(const std::string& name) :
ICommand(name) {}

SaveasCommand::~SaveasCommand() {}
