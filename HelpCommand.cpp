#include "HelpCommand.h"

void HelpCommand::execute(const std::string& param, Database* & obj) {
    std::cout << "warning: indexation starts from 0!\n";
    std::cout << "open (P1)" << "\n";
    std::cout << "\topens a file\n";

    std::cout << "close\n";
    std::cout << "\tcloses the opened file\n";

    std::cout << "save\n";
    std::cout << "\tsaves to the opened file\n";

    std::cout << "saveas (P1)" << "\n";
    std::cout << "\tsaves to specific file\n";

    std::cout << "help\n";
    std::cout << "\tdisplays available commands\n";   

    std::cout << "exit\n";
    std::cout << "\texits the program\n";

    std::cout << "import (P1) (P2)" << "\n";
    std::cout << "\timports table by name and file \n";  

    std::cout << "showtables\n";
    std::cout << "\tdisplays loaded tables names\n";

    std::cout << "describe (P1)" << "\n";
    std::cout << "\tshows column types of table by name\n"; 

    std::cout << "print (P1)" << "\n";
    std::cout << "\tprints specific table\n";

    std::cout << "export (P1) (P2)" << "\n";
    std::cout << "\texports table by name to file\n";  

    std::cout << "select (P1) (P2) (P3)" << "\n";
    std::cout << "\tcolumn index | value to be searched | table name\n";

    std::cout << "addcolumn (P1) (P2) (P3)" << "\n";
    std::cout << "\ttable name | column name | column type\n";

    std::cout << "update (P1) (P2) (P3) (P4) (P5)" << "\n";
    std::cout << "\ttable name | search column | search value | target column | target value\n"; 

    std::cout << "delete (P1) (P2) (P3)" << "\n";
    std::cout << "\ttable name | search column | search value\n";

    std::cout << "insert (P1) (P20) .... (P2n)" << "\n";
    std::cout << "\ttable name | column values...\n"; 
    std::cout << "\tn depends on number of columns\n";   

    std::cout << "innerjoin (P1) (P2) (P3) (P4)" << "\n";
    std::cout << "\ttable name 1 | column table 1 | table name 2 | column table 2\n";   

    std::cout << "rename (P1) (P2)" << "\n";
    std::cout << "\told table name | new table name\n";

    std::cout << "count (P1) (P2) (P3)" << "\n";
    std::cout << "\ttable name | search column | search value\n";

    std::cout << "aggregate (P1) (P2) (P3) (P4) (P5)" << "\n";
    std::cout << "\ttable name | search col | search value | target column | operation\n";                        
}

HelpCommand::HelpCommand(const std::string& name) :
ICommand(name) {}

HelpCommand::~HelpCommand() {}
