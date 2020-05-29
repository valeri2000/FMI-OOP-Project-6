#include "HelpCommand.h"

void HelpCommand::execute(const std::string& param, Database* & obj) {
    std::cout << "open ..... \n";
    std::cout << "\topens a file\n";

    std::cout << "close\n";
    std::cout << "\tcloses the opened file\n";

    std::cout << "save\n";
    std::cout << "\tsaves to the opened file\n";

    std::cout << "saveas ..... \n";
    std::cout << "\tsaves to specific file\n";

    std::cout << "help\n";
    std::cout << "\tdisplays available commands\n";   

    std::cout << "exit\n";
    std::cout << "\texits the program\n";

    std::cout << "import ..... ..... \n";
    std::cout << "\timports table by name and file \n";  

    std::cout << "showtables\n";
    std::cout << "\tdisplays loaded tables names\n";

    std::cout << "describe .....n";
    std::cout << "\tshows column types of table by name\n"; 

    std::cout << "print .....n";
    std::cout << "\tprints specific table\n";

    std::cout << "export ..... .....n";
    std::cout << "\texports table by name to file\n";  

    std::cout << "select ..... ...... ......n";
    std::cout << "\tcolumn index | value to be searched | table name\n";

    std::cout << "addcolumn ..... ...... ......n";
    std::cout << "\ttable name | column name | column type\n";

    std::cout << "update ..... ...... ...... ...... ......n";
    std::cout << "\ttable name | search column | search value | target column | target value\n"; 

    std::cout << "delete ..... ...... ......n";
    std::cout << "\ttable name | search column | search value\n";

    std::cout << "insert ..... ............n";
    std::cout << "\ttable name | column values...\n";    

    std::cout << "innerjoin ..... ...... ...... .....n";
    std::cout << "\ttable name 1 | column table 1 | table name 2 | column table 2\n";   

    std::cout << "rename ..... ......n";
    std::cout << "\told table name | new table name\n";

    std::cout << "count ..... ...... ......n";
    std::cout << "\ttable name | search column | search value\n";

    std::cout << "aggregate ..... ...... ...... ...... ......n";
    std::cout << "\ttable name | search col | search value | target column | operation\n";                        
}

HelpCommand::HelpCommand(const std::string& name) :
ICommand(name) {}

HelpCommand::~HelpCommand() {}
