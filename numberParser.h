#pragma once
#include <string>
#include "iparser.h"
#include "tokenNumber.h"

namespace VerbioTechTest
{
	/**
	 * @brief The algorithm is simple. There are two types of 'numbers':
	 * real numbers (one or twenty) and magnitudes (hundred or million).
	 * In english, only can appear one magnitude greater or equals than thousand
	 * (if there is the word million, there can't be the word billion).
	 *
	 * I accumulate in mCurrent numbers less than thousand. When I found a
	 * magnitude greater or equals than thousand, I multiply and move the
	 * result to mTotal, reseting mCurrent.
	 *
	 * I do this process again and again, but I am careful with the multiply
	 * operation. There are some constraints.
	 *
	 */
	class NumberParser : public IParser
	{
	public:
		NumberParser();

		/**
		 * @brief Add the given word to the current value
		 *
		 * @param word std::string that represents the new added word
		 * @return false if the result is not valid, true otherwise
		 */
		bool addWord(const std::string &word) override;

		/**
		 * @brief Get the value of the parsed number
		 *
		 * @return std::string with the parsed value
		 */
		int getValue() override;

		/**
		 * @brief Check if a word can be managed by this parser
		 *
		 * @param word std::string that represents a word
		 * @return true if the given word can be managed by this parser, false otherwise
		 */
		bool isValidWord(const std::string &word) const override;

		/**
		 * @brief Starts a new parsing
		 *
		 */
		void reset() override;

	private:
		/**
		 * @brief Add the given TokenNumber
		 *
		 * @param other TokenNumber to add
		 * @return true if everything goes well, false otherwise
		 */
		bool add(const TokenNumber &other);

		/**
		 * @brief Multiply the given TokenNumber
		 *
		 * @param other TokenNumber to multiply
		 * @return true if everything goes well, false otherwise
		 */
		bool multiply(const TokenNumber &other);

		// TokenNumber which accumulates large values, above one thousand
		TokenNumber mTotal;

		// TokenNumber which accumulates small values, bellow one thousand
		TokenNumber mCurrent;
	};
}