#include "InsertCommand.h"
#include "Parser.h"

void InsertCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    std::vector<std::string> params;
    Parser::parseLineToParam(param, params);

    std::string saveName = params[0];
    for(unsigned int i = 1; i < params.size(); ++i) {
        params[i - 1] = params[i];
    }
    params.pop_back();

    obj->insertT(saveName, params);
}

InsertCommand::InsertCommand(const std::string& name) :
ICommand(name) {}

InsertCommand::~InsertCommand() {}
