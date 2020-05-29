#include "ErrorState.h"

Flag ErrorState::state = Flag::GOOD;
std::unordered_map<Flag, std::string> ErrorState::msgs = {
    {Flag::BAD_INDEX, "Invalid index!"},
    {Flag::BAD_NODATA, "No data loaded! First you need to open file to load data."},
    {Flag::BAD_REOPEN, "You need to close current file first, in order to open a new one."},
    {Flag::BAD_FILE, "The given file is invalid!"},
    {Flag::BAD_COMMAND, "Invalid command! Type 'help' to view available commands and usage."},
    {Flag::BAD_TABLE_NAME, "Invalid table name!"},
    {Flag::BAD_OPERATION, "Invalid operation!"},
    {Flag::BAD_TYPE, "Invalid type for column! (available types are 'int', 'string', 'double' or empty cell('NULL'))"}
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
