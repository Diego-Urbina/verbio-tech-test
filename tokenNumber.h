#pragma once

namespace VerbioTechTest
{
	struct TokenNumber
	{
		TokenNumber();

		TokenNumber(int value);

		TokenNumber &operator+(const TokenNumber &other);
		TokenNumber &operator*(const TokenNumber &other);

		bool operator<(const TokenNumber& rhs) const;
		bool operator>(const TokenNumber& rhs) const;
		bool operator<=(const TokenNumber& rhs) const;
		bool operator>=(const TokenNumber& rhs) const;

		bool isEmpty() const;

		void reset();

		/**
		 * Token numeric value
		 */
		int mValue;

		/**
		 * number of digits of mValue
		 */
		int mMagnitude;

	private:

		void calcMagnitude();
	};
}