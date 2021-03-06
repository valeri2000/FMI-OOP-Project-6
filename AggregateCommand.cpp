#include "AggregateCommand.h"
#include "Parser.h"
#include <iomanip>

void AggregateCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        ErrorState::setState(Flag::BAD_NODATA);
        return;
    }

    std::vector<std::string> params;
    Parser::parseLineToParam(param, params);

    if(params.size() != 5) {
        ErrorState::setState(Flag::BAD_COMMAND);
        return;
    }

    std::pair<int, bool> res1 = Parser::convertToInt(params[1]);
    std::pair<int, bool> res2 = Parser::convertToInt(params[3]);

    if(res1.second == false || res2.second == false || 
       res1.first < 0 || res2.first < 0) {
        ErrorState::setState(Flag::BAD_INDEX);
        return;
    }

    double operRes = obj->aggregateT(params[0], res1.first, params[2], res2.first, params[4]);

    if(ErrorState::getState() == Flag::GOOD) {
        std::cout << "Aggregate result: " <<
            std::fixed << std::setprecision(6) <<
            operRes << '\n';
    }
}

AggregateCommand::AggregateCommand(const std::string& name) :
ICommand(name) {}

AggregateCommand::~AggregateCommand() {}
