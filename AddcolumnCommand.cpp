#include "AddcolumnCommand.h"
#include "Parser.h"

void AddcolumnCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    std::vector<std::string> params;
    Parser::parseLineToParam(param, params);

    if(params.size() != 3) {
        ErrorState::setState(Flag::BAD_COMMAND);
        return;
    }

    obj->addColumnT(params[0], params[1], params[2]);
}

AddcolumnCommand::AddcolumnCommand(const std::string& name) :
ICommand(name) {}

AddcolumnCommand::~AddcolumnCommand() {}
