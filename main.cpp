#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "exercise.h"
#include "numberParser.h"

int interactiveMode()
{
	VerbioTechTest::Exercise exercise(new VerbioTechTest::NumberParser());

	std::string line;
	std::cout << "*** Starting interactive mode. Type :q for exit ***" << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line == ":q")
			break;
		std::cout << " => " << exercise.getSentence(line) << std::endl;
	}

	return 0;
}

int fileMode(char *filename)
{
	std::ifstream in(filename);
	if (!in)
	{
		std::cout << "Could not open file: '" << filename << "'\n";
		return 1;
	}

	VerbioTechTest::Exercise exercise(new VerbioTechTest::NumberParser());
	for (std::string line; std::getline(in, line);)
	{
		std::cout << line << std::endl;
		std::cout << " => " << exercise.getSentence(line) << std::endl;
	}

	return 0;
}

int test()
{
	VerbioTechTest::Exercise exercise(new VerbioTechTest::NumberParser());
	std::cout << exercise.getSentence("two million four hundred twelve thousand eight hundred seven apples") << std::endl;
	std::cout << exercise.getSentence("three million seven hundred fifty six thousand three hundred thirty three") << std::endl;
	std::cout << exercise.getSentence("I have two hundred and fourteen brothers and five sisters") << std::endl;
	std::cout << exercise.getSentence("I have two hundred fourteen hundred brothers and five sisters") << std::endl;
	std::cout << exercise.getSentence("TWELVE HUNDRED") << std::endl;
	std::cout << exercise.getSentence("two thousand one million") << std::endl;
	std::cout << exercise.getSentence("one million two thousand ") << std::endl;
	std::cout << exercise.getSentence("one million five hundred two thousand") << std::endl;
	std::cout << exercise.getSentence("one million five hundred two thousand eight hundred eighty eight") << std::endl;
	std::cout << exercise.getSentence("I want fourteen thousand million dollars") << std::endl;
	std::cout << exercise.getSentence("I want fourteen hundred million dollars") << std::endl;
	std::cout << exercise.getSentence("I want fourteen billion dollars") << std::endl;

	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		return interactiveMode();
	}

	if (argc == 2 && strcmp(argv[1], "-t") == 0)
	{
		return test();
	}

	if (argc == 3 && strcmp(argv[1], "-f") == 0)
	{
		std::string file(argv[2]);
		return fileMode(argv[2]);
	}

	std::cout << "Invalid launch options: \n"
			  << "VerbioTechnicalTest \t\t\tInteractive mode\n"
			  << "VerbioTechnicalTest -f filename \tRead sentences from file\n"
			  << "VerbioTechnicalTest -t \t\t\tTest mode" << std::endl;

	return 1;
}