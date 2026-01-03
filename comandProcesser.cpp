#include "getInput.hxx"

int returnInput(std::string input)
{ 
	if (input.size() >= 3 && input[3] == '\0')
	{
		if (input[0] == 'd' && input[1] == 'e' && input[2] == 'l')
			return 3;
		else if (input[0] == 'a' && input[1] == 'd' && input[2] == 'd')
			return 1;
		else if (input[0] == 'e' && input[1] == 'd' && input[2] == 'i')
			return 2;
		else if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i')
			return 4;
	}
	return -1; // Return -1 for invalid input
}

std::string returnContent(std::string input)
{
	if (input.size() > 4)
	{
		return input.substr(4);
	}
	return "";
}

int findBlank(std::string input)
{
		for (size_t i = 0; i < input.size(); ++i)
	{
		if (input[i] == ' ')
			return i;
	}
		return -1; // Return -1 if no blank space is found
}

int getAction(std::string input)
{
	int blankIndex = findBlank(input);
	if (blankIndex == -1)
	{
		return -1; // Return -1 if no blank space is found
	}
	else
	{
		size_t response;
		int result = std::stoi(input.substr(0, blankIndex), &response);
		if (response == input.substr(0, blankIndex).size())
		{
			return result;
		}
		else
		{
			return -1; // Return -1 if conversion fails
		}
	}
}


auto returnCommand(std::string input) -> command
{
	command result;
	result.action = returnInput(input);
	result.indexOfContent = getAction(input.substr(4));
	result.content = returnContent(input);
	return result;	
}