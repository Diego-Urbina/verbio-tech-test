#pragma once
#include <string>

class IParser
{
public:
    virtual bool addWord(const std::string &word) = 0;

    virtual int getValue() = 0;

    virtual bool isValidWord(const std::string &word) const = 0;

    virtual bool isActive() const
    {
        return mIsActive;
    }

    virtual void reset() = 0;

protected:
    bool mIsActive;
};