#include "App.h"
#include "CommandList.h"

App* App::instance = nullptr;

App* App::getInstance() {
    if(instance == nullptr) {
        instance = new App();
    }

    return instance;
}

App::App() : database(nullptr) {
    this->invoker = new Invoker({
        new OpenCommand("open"),
        new CloseCommand("close"),
        new SaveCommand("save"),
        new SaveasCommand("saveas"),
        new HelpCommand("help"),
        new ImportCommand("import"),
        new ShowtablesCommand("showtables"),
        new DescribeCommand("describe"),
        new PrintCommand("print"),
        new ExportCommand("export"),
        new SelectCommand("select"),
        new AddcolumnCommand("addcolumn"),
        new UpdateCommand("update"),
        new DeleteCommand("delete"),
        new InsertCommand("insert"),
        new InnerjoinCommand("innerjoin"),
        new RenameCommand("rename"),
        new CountCommand("count"),
        new AggregateCommand("aggregate")
    });
}

App::~App() {
    delete this->database;
    this->database = nullptr;

    delete this->invoker;
    this->invoker = nullptr;
}

void App::run() {
    while(this->invoker->parseCommand(this->database) == true) {}
}
