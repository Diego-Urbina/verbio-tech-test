#include "tokenNumber.h"

namespace VerbioTechTest
{
	TokenNumber::TokenNumber() : mValue{ 0 }, mMagnitude{ 0 } {}

	TokenNumber::TokenNumber(int value) : mValue{ value }, mMagnitude{ 0 }
	{
		calcMagnitude();
	}

	TokenNumber &TokenNumber::operator+(const TokenNumber &other)
	{
		mValue += other.mValue;
		calcMagnitude();
		return *this;
	}

	TokenNumber &TokenNumber::operator*(const TokenNumber &other)
	{
		mValue *= other.mValue;
		calcMagnitude();
		return *this;
	}

	bool TokenNumber::operator<(const TokenNumber& rhs) const
	{
		return mMagnitude < rhs.mMagnitude;
	}

	bool TokenNumber::operator>(const TokenNumber& rhs) const
	{
		return rhs < *this;
	}

	bool TokenNumber::operator<=(const TokenNumber& rhs) const
	{
		return !(*this > rhs);
	}

	bool TokenNumber::operator>=(const TokenNumber& rhs) const
	{
		return !(*this < rhs);
	}

	bool TokenNumber::isEmpty() const
	{
		return mValue == 0 && mMagnitude == 0;
	}

	void TokenNumber::reset()
	{
		mValue = 0;
		mMagnitude = 0;
	}

	void TokenNumber::calcMagnitude()
	{
		int value = mValue;
		mMagnitude = 0;
		while (value > 0)
		{
			mMagnitude++;
			value /= 10;
		}
	}
}