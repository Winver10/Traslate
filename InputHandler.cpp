#include "getInput.hxx"
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

// This file provides implementations for input handling functions
// that were declared in getInput.hxx

int returnInput(std::string input)
{ 
    // Convert to lowercase for easier matching
    std::string lowerInput = input;
    for (auto& c : lowerInput) {
        c = std::tolower(c);
    }

    if (lowerInput.length() >= 3) {
        if (lowerInput.substr(0, 3) == "add")
            return 1;
        else if (lowerInput.substr(0, 4) == "edit")
            return 2;
        else if (lowerInput.substr(0, 3) == "del")
            return 3;
        else if (lowerInput.substr(0, 4) == "exit")
            return 4;
    }
    return -1; // Return -1 for invalid input
}

std::string returnContent(std::string input)
{
    size_t pos = input.find(' ');
    if (pos != std::string::npos && pos + 1 < input.length()) {
        return input.substr(pos + 1);
    }
    return "";
}

std::string getAction(std::string input)
{
    size_t pos = input.find(' ');
    if (pos != std::string::npos) {
        return input.substr(0, pos);
    }
    return input;
}

int getItemNumber(const std::string input) {
    std::istringstream iss(input);
    std::string action;
    int number;
    
    iss >> action >> number;
    return number;
}