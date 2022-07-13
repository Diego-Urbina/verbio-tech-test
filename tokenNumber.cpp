#include "tokenNumber.h"

TokenNumber::TokenNumber(int value) : mValue{value}, mMagnitude{0}
{
    while (value > 0)
    {
        mMagnitude++;
        value /= 10;
    }
}

TokenNumber &TokenNumber::operator+(const TokenNumber &other)
{
    mValue += other.mValue;
    mMagnitude = std::max(mMagnitude, other.mMagnitude);
    return *this;
}

TokenNumber &TokenNumber::operator*(const TokenNumber &other)
{
    mValue *= other.mValue;
    mMagnitude = std::max(mMagnitude, other.mMagnitude);
    return *this;
}

/*void TokenNumber::multiply(int mul)
{
    mValue *= mul;
    mMagnitude = mul;
}*/

void TokenNumber::reset()
{
    mValue = 0;
    mMagnitude = 0;
}