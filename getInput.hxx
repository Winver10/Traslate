#pragma once

#include <string>
#include <iostream>
#include <string>

inline std::string getInput()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}
int returnInput(std::string input);
std::string returnContent(std::string input);
int getAction(std::string input);
int findBlank(std::string input);

struct command
{
	int action;
	int indexOfContent;
	std::string content;
};

auto returnCommand(std::string input) -> command;
