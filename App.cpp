#include "App.h"

App* App::instance = nullptr;

App* App::getInstance() {
    if(instance == nullptr) {
        instance = new App();
    }

    return instance;
}

App::App() : database(nullptr) {}

void App::run() {
    
}
