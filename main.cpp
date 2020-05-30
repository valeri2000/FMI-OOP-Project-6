#include <iostream>
#include "App.h"

int main() {
    App* application = App::getInstance();
    application->run();

    delete application;
    return 0;
}
