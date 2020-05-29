#include "DeleteCommand.h"
#include "Parser.h"

void DeleteCommand::execute(const std::string& param, Database* & obj) {
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

    std::pair<int, bool> res = Parser::convertToInt(params[1]);

    if(res.second == false || res.first < 0) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    obj->delT(params[0], res.first, params[2]);
}

DeleteCommand::DeleteCommand(const std::string& name) :
ICommand(name) {}

DeleteCommand::~DeleteCommand() {}
