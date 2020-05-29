#include "AggregateCommand.h"
#include "Parser.h"

void AggregateCommand::execute(const std::string& param, Database* & obj) {
    if(obj == nullptr) {
        std::cout << "Open first!\n";
        return;
    }

    std::vector<std::string> params;
    Parser::parseLineToParam(param, params);

    if(params.size() != 5) {
        std::cout << "Inv\n";
        return;
    }

    std::pair<int, bool> res1 = Parser::convertToInt(params[1]);
    std::pair<int, bool> res2 = Parser::convertToInt(params[3]);

    if(res1.second == false || res2.second == false || 
       res1.first < 0 || res2.first < 0) {
        std::cout << "Invalid\n";
        return;
    }

    obj->aggregateT(params[0], res1.first, params[2], res2.first, params[4]);
}

AggregateCommand::AggregateCommand(const std::string& name) :
ICommand(name) {}

AggregateCommand::~AggregateCommand() {}
