#include "RenameCommand.h"
#include "Parser.h"

void RenameCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    std::vector<std::string> params;
    Parser::parseLineToParam(param, params);

    if(params.size() != 2) {
        std::cout << "Invaldi!\n";
    }

    obj->renameT(params[0], params[1]);
}

RenameCommand::RenameCommand(const std::string& name) :
ICommand(name) {}

RenameCommand::~RenameCommand() {}
