#include "ErrorState.h"

Flag ErrorState::state = Flag::GOOD;
std::unordered_map<Flag, std::string> ErrorState::msgs = {
    {Flag::BAD_INDEX, "Invalid index! (out of range)"},
    {Flag::BAD_TYPE, "Invalid type for column! (available types are 'int',\
                        'string', 'double' or empty cell('NULL'))"}
};

const Flag& ErrorState::getState() {
    return state;
}

const std::string& ErrorState::getMessage() {
    return msgs[state];
}

void ErrorState::setState(const Flag& newState) {
    state = newState;
}
