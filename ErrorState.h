#ifndef __ERRORSTATE_H_INCLUDED
#define __ERRORSTATE_H_INCLUDED

#include <iostream>
#include <unordered_map>

/// \brief Messages for errors (of enum type)
enum class Flag {
    BAD_INDEX,
    BAD_TYPE,
    BAD_COMMAND,
    BAD_NODATA,
    BAD_REOPEN,
    BAD_FILE,
    BAD_TABLE_NAME,
    BAD_OPERATION,
    GOOD
};

/// \brief Class which tracks errors formed by invalid input data
class ErrorState {
    public:
        static Flag state; ///< current state
        static std::unordered_map<Flag, std::string> msgs; ///< matching for state -> real message

        /// \brief Getter for current state
        static const Flag& getState();

        /// \brief Getter for actual message from current state
        static const std::string& getMessage();

        /// \brief Setter for state
        /// \param 'const Flag&' which is new state flag 
        static void setState(const Flag&);
};

#endif
