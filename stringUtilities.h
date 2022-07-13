#pragma once
#include <algorithm>
#include <string>

namespace VerbioTechTest
{
	namespace StringUtilities
	{
		static std::string toLower(const std::string &sentence)
		{
			std::string dest;
			dest.resize(sentence.size());
			std::transform(sentence.begin(), sentence.end(), dest.begin(), ::tolower);
			return dest;
		}
	}
}