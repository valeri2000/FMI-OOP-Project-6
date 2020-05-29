#include "CloseCommand.h"

void CloseCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    delete obj;
    obj = nullptr;
}

CloseCommand::CloseCommand(const std::string& name) :
ICommand(name) {}

CloseCommand::~CloseCommand() {}
