#pragma once
#include "string"
#include "tokenNumber.h"

class NumberParser
{
public:
    /**
     * @brief Add the given word to the current value
     *
     * @param word std::string that represents the new added word
     * @return false if the result is not valid, true otherwise
     */
    bool addWord(const std::string &word);

    /**
     * @brief Get the value
     *
     * @return std::string with the parsed value
     */
    std::string getValue();

    // Return true if a parsing is active
    bool isActive();

private:
    // Starts a new parsing
    void reset();

    bool add(const TokenNumber &other);

    bool multiply(const TokenNumber &other);

    TokenNumber mTotal;
    TokenNumber mCurrent;
    bool mIsActive;
};