#include "DeleteCommand.h"
#include "Parser.h"

void DeleteCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    std::vector<std::string> params;
    Parser::parseLineToParam(param, params);

    if(params.size() != 3) {
        std::cout << "Invalid!\n";
        return;
    }

    std::pair<int, bool> res = Parser::convertToInt(params[1]);

    if(res.second == false || res.first < 0) {
        std::cout << "Invalid!\n";
        return;
    }

    obj->delT(params[0], res.first, params[2]);
}

DeleteCommand::DeleteCommand(const std::string& name) :
ICommand(name) {}

DeleteCommand::~DeleteCommand() {}
