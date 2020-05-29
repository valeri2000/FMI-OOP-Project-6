#include "ExportCommand.h"

void ExportCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    std::string param1, param2;
    for(unsigned int i = 0; i < param.size(); ++i) {
        if(param[i] == ' ') {
            for(unsigned int j = i + 1; j < param.size(); ++j) {
                param2 += param[j];
            }
            break;
        }

        param1 += param[i];
    }

    if(param1.size() == 0 || param2.size() == 0) {
        std::cout << "INvalid command\n";
        return;
    }

    obj->exportT(param1, param2);
}

ExportCommand::ExportCommand(const std::string& name) :
ICommand(name) {}

ExportCommand::~ExportCommand() {}
