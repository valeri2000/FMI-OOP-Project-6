#include "SelectCommand.h"
#include "Parser.h"
#include <algorithm>

void SelectCommand::execute(const std::string& param, Database* & obj) {
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

    std::pair<int, bool> getIndex = Parser::convertToInt(params[0]);

    if(getIndex.second == false || getIndex.first < 0) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    obj->selectT(params[2], getIndex.first, params[1]);
}

SelectCommand::SelectCommand(const std::string& name) :
ICommand(name) {}

SelectCommand::~SelectCommand() {}
