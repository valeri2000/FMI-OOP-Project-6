#include <iostream>
#include "App.h"

int main() {
    App* application = App::getInstance();
    application->run();

    return 0;
}
