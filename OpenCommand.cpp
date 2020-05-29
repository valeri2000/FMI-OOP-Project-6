#include "OpenCommand.h"

void OpenCommand::execute(const std::string& param, Database* & obj) {
    if(obj != nullptr) {
        ErrorState::setState(Flag::BAD_REOPEN);
        return;
    }

    obj = new Database(param);

    if(ErrorState::getState() != Flag::GOOD) {
        delete obj;
        obj = nullptr;
    }
}

OpenCommand::OpenCommand(const std::string& name) :
ICommand(name) {}

OpenCommand::~OpenCommand() {}
