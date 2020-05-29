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

        std::cout << ErrorState::getMessage() << '\n';
    }
}

OpenCommand::OpenCommand(const std::string& name) :
ICommand(name) {}

OpenCommand::~OpenCommand() {}
