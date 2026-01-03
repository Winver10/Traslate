#pragma once

#include <string>
#include <iostream>

inline std::string getInput()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}
int returnInput(std::string input);
std::string returnContent(std::string input);
std::string getAction(std::string input);
int findBlank(std::string input);