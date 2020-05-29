#include "CountCommand.h"
#include "Parser.h"

void CountCommand::execute(const std::string& param, Database* & obj) {
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

    unsigned int counter = obj->countT(params[0], res.first, params[2]);

    if(ErrorState::getState() == Flag::GOOD) {
        std::cout << "Counted: " << counter << '\n'; 
    }
}

CountCommand::CountCommand(const std::string& name) :
ICommand(name) {}

CountCommand::~CountCommand() {}
