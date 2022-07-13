#include "iostream"
#include "parser.h"

int main()
{
    Parser parser;
    std::cout << parser.getSentence("two million four hundred twelve thousand eight hundred seven apples") << std::endl;
    std::cout << parser.getSentence("three million seven hundred fifty six thousand three hundre thirty three") << std::endl;
    std::cout << parser.getSentence("I have two hundred and fourteen brothers and five sisters") << std::endl;

    return 0;
}