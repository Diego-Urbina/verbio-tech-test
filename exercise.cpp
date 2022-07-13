#include "exercise.h"
#include <sstream>
#include "numbersUtilities.h"
#include "stringUtilities.h"

namespace VerbioTechTest
{
	Exercise::Exercise(IParser *parser) : mParser{parser}, mValidState{true} {}

	Exercise::~Exercise()
	{
		delete mParser;
		mParser = nullptr;
	}

	std::string Exercise::getSentence(std::string sentence)
	{
		reset();

		std::ostringstream out;
		std::istringstream in(sentence);
		std::string word;

		/* I know there is a problem with this tokenizer method.
		 * I use whitespace for spliting the string, and that's the reason
		 * because it doesn't split properly a word follows by other char.
		 * It doesn't detect "Five?" for example. I tried to use regex
		 * but I don't have enougth time and I consider that this is not
		 * the main porpouse of the test
		 */
		while (in >> word && validState())
		{
			// If a word can be managed by the parser...
			auto lowerWord = StringUtilities::toLower(word);
			if (mParser->isValidWord(lowerWord))
			{
				mValidState = mParser->addWord(lowerWord);
			}
			else
			{
				flushFromParser(out);
				out << word << ' ';
			}
		}

		if (validState())
		{
			flushFromParser(out);
		}
		else
		{
			// Error management
			out.str("");
			out.clear();
			out << "[ERROR] Invalid number format: " << sentence;
		}

		return out.str();
	}

	void Exercise::flushFromParser(std::ostringstream &out)
	{
		if (mParser->isActive())
		{
			out << mParser->getValue() << ' ';
		}
	}

	bool Exercise::validState() const
	{
		return mValidState;
	}

	void Exercise::reset()
	{
		mValidState = true;
		mParser->reset();
	}
}