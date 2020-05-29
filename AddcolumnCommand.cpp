#include "AddcolumnCommand.h"
#include <algorithm>

void AddcolumnCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    std::string param1, param2, param3;
    unsigned int l, r;

    for(unsigned i = 0; i < param.size(); ++i) {
        if(param[i] == ' ') {
            l = i + 1;
            break;
        }

        param1 += param[i];
    }

    for(unsigned j = param.size() - 1; ; --j) {
        if(param[j] == ' ') {
            r = j - 1;
            break;
        }

        param3 += param[j];

        if(j == 0) {
            break;
        }
    }
    std::reverse(param3.begin(), param3.end());

    for(unsigned int i = l; i <= r; ++i) {
        param2 += param[i];
    }

    obj->addColumnT(param1, param2, param3);
}

AddcolumnCommand::AddcolumnCommand(const std::string& name) :
ICommand(name) {}

AddcolumnCommand::~AddcolumnCommand() {}
