#include "numberParser.h"
#include "numbersUtilities.h"

bool NumberParser::addWord(const std::string &word)
{
    mIsActive = true;

    if (NumberUtilities::isNumber(word))
    {
        return add(TokenNumber(NumberUtilities::numbers[word]));
    }
    else if (NumberUtilities::isMagnitude(word))
    {
        return multiply(TokenNumber(NumberUtilities::magnitudes[word]));
    }

    return false;
}

std::string NumberParser::getValue()
{
    int value = mTotal.mValue + mCurrent.mValue;
    reset();
    return std::to_string(value);
}

void NumberParser::reset()
{
    mIsActive = false;
    mTotal.reset();
    mCurrent.reset();
}

bool NumberParser::isActive()
{
    return mIsActive;
}

bool NumberParser::add(const TokenNumber &other)
{
    // add other to mCurrent
    // if mCurrent is empty or mCurrent.magnitude > other.magnitude

    if (mCurrent.mMagnitude != 0 && mCurrent.mMagnitude < other.mMagnitude)
    {
        return false;
    }

    mCurrent = mCurrent + other;
    return true;
}

bool NumberParser::multiply(const TokenNumber &other)
{
    // multiply mCurrent with magnitude and move to mTotal
    // reset mCurrent
    if (mCurrent.mValue == 0 || mCurrent.mMagnitude >= other.mMagnitude)
    {
        return false;
    }

    mCurrent = mCurrent * other;
    if (mCurrent.mMagnitude >= 4)
    {
        mTotal = mTotal + mCurrent;
        mCurrent.reset();
    }
    return true;
}