#ifndef __PARSER_H_INCLUDED
#define __PARSER_H_INCLUDED

#include <utility>
#include <iostream>

/// \brief Class for converting input to column type values.
class Parser {
    public:
        /// \brief Static function to convert user input to integer.
        /// \param parameter 'const string' which is the user input
        /// \return 'pair<int, bool>' which has a true/false as a second value\n
        /// depending on whether the conversion is successful
        static std::pair<int, bool>
            convertToInt(const std::string&);

        /// \brief Static function to convert user input to 'double'.
        /// \param parameter 'const string' which is the user input
        /// \return 'pair<double, bool>' which has a true/false as a second value\n
        /// depending on whether the conversion is successful
        static std::pair<double, bool>
            convertToDouble(const std::string&);

        /// \brief Static function to say whether user input is of 'string' type.
        /// \param parameter 'const string' which is the user input
        /// \return 'bool' which is true/false
        static bool
            isString(const std::string&);

        /// \brief Static function to say whether user input is 'NULL'.
        /// \param parameter 'const string' which is the user input
        /// \return 'bool' which is true/false
        static bool
            isNull(const std::string&);
};

#endif
