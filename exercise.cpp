#include <sstream>
#include "parser.h"
#include "numbersUtilities.h"

std::string Parser::getSentence(const std::string &sentence)
{
    std::ostringstream out;

    std::istringstream in(sentence);
    std::string word;
    while (in >> word && validState())
    {
        if (isNumber(word))
        {
            mNumberParser.addWord(word);
        }
        else
        {
            if (mNumberParser.isActive())
            {
                out << mNumberParser.getValue() << ' ';
            }
            out << word << ' ';
        }
    }

    if (validState())
    {
        if (mNumberParser.isActive())
        {
            out << mNumberParser.getValue() << ' ';
        }
    }
    else
    {
        // Error management
    }

    return out.str();
}

bool Parser::isNumber(const std::string &word)
{
    return NumberUtilities::isNumber(word) || NumberUtilities::isMagnitude(word);
}

bool Parser::validState()
{
    return true;
}