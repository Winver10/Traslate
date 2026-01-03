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

std::string getAction(std::string input)
{
	
}