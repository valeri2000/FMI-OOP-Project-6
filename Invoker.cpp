#include "Invoker.h"
#include <iostream>
#include <cassert>

Invoker::Invoker(const std::vector<ICommand*>& data) :
commands(data) {}

Invoker::~Invoker() {
    for(ICommand* &i : this->commands) {
        delete i;
    }

    this->commands.clear();
}

bool Invoker::parseCommand(Database* &obj) {
    assert(ErrorState::getState() == Flag::GOOD);

    std::cout << "\nEnter command: ";
    
    std::string line;
    std::getline(std::cin, line);

    unsigned int size = line.size();

    if(size == 0) {
        return true;
    }

    std::string currCommand;
    unsigned int index = 0;
    for(; index < size; ++index) {
        if(line[index] == ' ') {
            index++;
            break;
        }

        currCommand += line[index];
    }

    if(currCommand.size() == 0) {
        return true;
    }

    if(currCommand == "exit") { //Special case
        std::cout << "Exiting program ...\n";

        return false;
    }

    std::string parameters;
    for(; index < size; ++index) {
        parameters += line[index];
    }

    bool found = false;
    for(ICommand* command : this->commands) {
        if(command->getCommandName() == currCommand) {
            command->execute(parameters, obj);
            found = true;
            break;
        } 
    }

    if(!found) {
        ErrorState::setState(Flag::BAD_COMMAND);
    }

    return true;
}
