#include "SaveCommand.h"

void SaveCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    if(param.size() > 0) {
        ErrorState::setState(Flag::BAD_COMMAND);
        return;
    }
    
    obj->saveToInputFile();
}

SaveCommand::SaveCommand(const std::string& name) :
ICommand(name) {}

SaveCommand::~SaveCommand() {}
