#include "Parser.h"

std::pair<int, bool>
Parser::convertToInt(const std::string& input) {
    std::pair<int, bool> wrong = std::make_pair(0, false);

    int n = (int)input.size();
    if(n == 0) {
        return wrong;
    }

    int startIndex = 0;
    bool negative = false;
    if(input[0] == '+') {
        startIndex++;
    } else if(input[0] == '-') {
        startIndex++;
        negative = true;
    }

    int res = 0;
    bool in = false;
    for(int i = startIndex; i < n; ++i) {
        char curr = input[i];

        if(curr >= '0' && curr <= '9') {
            in = true;
            res = res * 10 + curr - '0';
        } else {
            return wrong;
        }
    }

    if(!in) {
        return wrong;
    }

    res = res * (negative ? (-1) : (1));
    return std::make_pair(res, true);
}       

std::pair<double, bool>
Parser::convertToDouble(const std::string& input) {
    std::pair<double, bool> wrong = std::make_pair(0, false);

    int n = (int)input.size();
    if(n == 0) {
        return wrong;
    }

    int startIndex = 0;
    bool negative = false;
    if(input[0] == '+') {
        startIndex++;
    } else if(input[0] == '-') {
        startIndex++;
        negative = true;
    }

    double res = 0;
    bool in = false;
    for(int i = startIndex; i < n; ++i) {
        char curr = input[i];

        if(curr >= '0' && curr <= '9') {
            in = true;
            res = res * 10 + curr - '0';
        } else if(curr == '.') {
            int step = 10;

            bool newIn = false;
            for(int j = i + 1; j < n; ++j) {
                if(input[j] >= '0' && input[j] <= '9') {
                    newIn = true;
                    res = res + (input[j] - '0') * 1.0 / step;
                    step *= 10;
                } else {
                    return wrong;
                }
            }

            if(!newIn) {
                return wrong;
            }

            break;
        } else {
            return wrong;
        }
    }

    if(!in) {
        return wrong;
    }

    res = res * (negative ? (-1) : 1);
    return std::make_pair(res, true);
}  

bool
Parser::isString(const std::string& input) {
    if((int)input.size() >= 2 && 
        input[0] == '"' && 
        input.back() == '"') {
        return true;
    }

    return false;
}   

bool
Parser::isNull(const std::string& input) {
    return input == "NULL";
}       

void Parser::parseLineToParam(
    const std::string& line, 
    std::vector<std::string>& params
) {
    params.clear();
    std::string currParam;

    bool startedString = false;
    unsigned int size = line.size();

    for(unsigned i = 0; i < size; ++i) {
        if(line[i] == ' ') {
            if(startedString == true) {
                currParam += line[i];
            } else {
                if(currParam.size() > 0) {
                    params.push_back(currParam);
                }
                
                currParam = "";
            }
        } else if(line[i] == '"') {
            if(startedString == true) {
                startedString = false;

                currParam += line[i];
                params.push_back(currParam);
                currParam = "";
            } else {
                startedString = true;

                currParam += line[i];
            }
        } else {
            currParam += line[i];
        }
    }

    if(currParam.size() > 0) {
        params.push_back(currParam);
    }
}
