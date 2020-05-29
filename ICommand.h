#ifndef __ICOMMAND_H_INCLUDED
#define __ICOMMAND_H_INCLUDED

#include <vector>
#include <iostream>

/// \brief Interface class for all commands
class ICommand {
    private:
        std::string commandName; ///< command name as string

    public:
        /// \brief Constructor by command name as parameter
        ICommand(const std::string&);

        /// \brief Virtual destructor for deleting through base class
        virtual ~ICommand();

        /// \brief Pure virtual method to execute an action
        /// \param 'const string' which is all the parameters combined
        virtual void execute(const std::string&) = 0;

        /// \brief Pure virtual getter for command name for recognizing commands
        /// \return 'const string&' which is command name
        const std::string& getCommandName() const;
};

#endif
