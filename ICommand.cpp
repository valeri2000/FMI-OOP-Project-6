#include "ICommand.h"

ICommand::ICommand(const std::string& newName) :
commandName(newName) {}

ICommand::~ICommand() {}

const std::string& ICommand::getCommandName() const {
    return this->commandName;
}
