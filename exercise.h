#pragma once
#include <string>
#include "numberParser.h"
#include "iparser.h"

namespace VerbioTechTest
{
	class Exercise
	{
	public:
		Exercise(IParser *parser);

		~Exercise();

		/**
		 * @brief Given a string, parse it with the parser passed in the ctor
		 *
		 * @param sentence
		 * @return std::string
		 */
		std::string getSentence(std::string sentence);

	private:
		void flushFromParser(std::ostringstream &out);

		bool validState() const;

		void reset();

		IParser *mParser;

		bool mValidState;
	};
}