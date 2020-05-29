#include "SelectCommand.h"
#include "Parser.h"
#include <algorithm>

void SelectCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    std::string param1, param2, param3;
    unsigned l, r;

    for(unsigned int i = 0; i < param.size(); ++i) {
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

    if(param1.size() < 1 || param2.size() < 1 || param3.size() < 1) {
        std::cout << "Invalid command!\n";
        return;
    }

    std::pair<int, bool> res = Parser::convertToInt(param1);

    if(res.second == false || res.first < 0) {
        std::cout << "Invalid command!\n";
        return;
    }

    obj->selectT(param3, res.first, param2);
}

SelectCommand::SelectCommand(const std::string& name) :
ICommand(name) {}

SelectCommand::~SelectCommand() {}
