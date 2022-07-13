#pragma once
#include <string>
#include "numberParser.h"

class Parser
{
public:
    std::string getSentence(const std::string &sentence);

private:
    bool isNumber(const std::string &word);

    bool validState();

    // TODO extender a std::vector<IParser> mParsers;
    NumberParser mNumberParser;
};