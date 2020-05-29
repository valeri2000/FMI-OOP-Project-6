#include "ImportCommand.h"

void ImportCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    std::string param1, param2;
    for(unsigned int i = 0; i < param.size(); ++i) {
        if(param[i] == ' ') {
            for(unsigned j = i + 1; j < param.size(); ++j) {
                param2 += param[j];
            }

            break;
        }

        param1 += param[i];
    }

    if(param1.size() && param2.size()) {
        obj->importT(param1, param2);
    } else {
        std::cout << "Invalid command!\n";
    }
}

ImportCommand::ImportCommand(const std::string& name) :
ICommand(name) {}

ImportCommand::~ImportCommand() {}
