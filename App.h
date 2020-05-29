#ifndef __APP_H_INCLUDED
#define __APP_H_INCLUDED

#include "Database.h"

class App {
    private:
        static App* instance;
        App();

        Database* database;

    public:
        static App* getInstance();

        void run();
};

#endif
