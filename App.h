#ifndef __APP_H_INCLUDED
#define __APP_H_INCLUDED

#include "Invoker.h"
#include "Database.h"

/// \brief App class to handle all data in the application
class App {
    private:
        static App* instance; ///< singleton principle 

        /// \brief Private constructor
        App();

        Database* database; ///< database member
        Invoker* invoker; ///< invoker member

    public:
        /// \brief Getter for the only instance
        /// \return 'App*'
        static App* getInstance();

        /// \brief Destructor for App class
        ~App();

        /// \brief The main method which runs tills program ends
        void run();
};

#endif
