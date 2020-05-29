#include "App.h"

App* App::instance = nullptr;

App* App::getInstance() {
    if(instance == nullptr) {
        instance = new App();
    }

    return instance;
}

App::App() : database(nullptr) {
    this->invoker = new Invoker(
    {}
    );
}

App::~App() {
    delete this->database;
    this->database = nullptr;

    delete this->invoker;
    this->invoker = nullptr;
}

void App::run() {
    while(this->invoker->parseCommand() == true) {}
}
