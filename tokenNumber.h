#pragma once
#include <string>

struct TokenNumber
{
    TokenNumber() : mValue{0}, mMagnitude{0} {}

    TokenNumber(int value);

    TokenNumber &operator+(const TokenNumber &other);

    TokenNumber &operator*(const TokenNumber &other);

    // void multiply(int mul);

    void reset();

    int mValue;
    int mMagnitude; // 0, 1, 10, 100, 1000, 1000000, 1000000000
};