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

        /// \brief Disable copy constructor
        Invoker(const Invoker&) = delete;

        /// \brief Disable operator=
        Invoker& operator = (const Invoker&) = delete;

        /// \brief Main method of Invoker class which parses commands
        /// \param first 'Database* &' which is actual reference to the database object
        /// \return 'bool' which is false if last command was 'exit'
        bool parseCommand(Database* &);
};

#endif
