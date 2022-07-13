#include "numberParser.h"
#include "numbersUtilities.h"

namespace VerbioTechTest
{
#define MAGNITUDE_TO_ACCUMULATE 4 // If thousand of greater is read, move the total to mTotal

	NumberParser::NumberParser()
	{
		mIsActive = false;
	}

	bool NumberParser::addWord(const std::string &word)
	{
		mIsActive = true;

		if (NumberUtilities::isNumber(word))
		{
			return add(TokenNumber(NumberUtilities::numbers[word]));
		}

		if (NumberUtilities::isMagnitude(word))
		{
			return multiply(TokenNumber(NumberUtilities::magnitudes[word]));
		}

		return NumberUtilities::andHundred == word;
	}

	int NumberParser::getValue()
	{
		// It may happen that the value is splitted between the two tokens
		int value = mTotal.mValue + mCurrent.mValue;
		reset();
		return value;
	}

	bool NumberParser::isValidWord(const std::string &word) const
	{
		return NumberUtilities::isNumber(word) || NumberUtilities::isMagnitude(word) || (word == NumberUtilities::andHundred && !mCurrent.isEmpty());
	}

	void NumberParser::reset()
	{
		mIsActive = false;
		mTotal.reset();
		mCurrent.reset();
	}

	bool NumberParser::add(const TokenNumber &other)
	{
		// add other to mCurrent, only if mCurrent is empty or has a greater magnitude
		// twenty one => OK
		// one twenty => NO OK

		if (!mCurrent.isEmpty() && mCurrent < other)
		{
			return false;
		}

		mCurrent = mCurrent + other;

		return true;
	}

	bool NumberParser::multiply(const TokenNumber &other)
	{
		// multiply mCurrent by other, only if mCurrent is not empty and has a lower magnitude
		// (two hundred) thousand => OK
		// (two thousand) hundred => NO OK
		if (mCurrent.isEmpty() || mCurrent >= other)
		{
			return false;
		}

		mCurrent = mCurrent * other;
		if (mCurrent.mMagnitude >= MAGNITUDE_TO_ACCUMULATE)
		{
			// If mafnitude is greater or equal than one thousand, it needs
			// to be moved to mTotal, but only if mTotal is empty or its
			// magnitude is greater than mCurrent's magnitude
			// two million three thousand => OK (million > thousand)
			// three thousand two million => NO OK
			if (!mTotal.isEmpty() && mTotal <= mCurrent)
			{
				return false;
			}

			mTotal = mTotal + mCurrent;
			mCurrent.reset();
		}

		return true;
	}
}