#include "ImportCommand.h"
#include "Parser.h"

void ImportCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    std::vector<std::string> params;
    Parser::parseLineToParam(param, params);

    if(params.size() != 2) {
        ErrorState::setState(Flag::BAD_COMMAND);
        return;
    }

    obj->importT(params[0], params[1]);
}

ImportCommand::ImportCommand(const std::string& name) :
ICommand(name) {}

ImportCommand::~ImportCommand() {}
