#ifndef __INVOKER_H_INCLUDED
#define __INVOKER_H_INCLUDED

#include "ICommand.h"

/// \brief Invoker class for handing commands
class Invoker {
    private:
        std::vector<ICommand*> commands; ///< all commands available

    public:
        /// \brief Constructor for invoker class
        /// \param 'const vector<ICommand*>' which is vector of commands
        Invoker(const std::vector<ICommand*>&);

        /// \brief Destructor for invoker class
        ~Invoker();

        /// \brief Main method of Invoker class which parses commands
        bool parseCommand(Database* &);
};

#endif
