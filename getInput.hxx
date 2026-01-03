#pragma once

#include <string>
#include <iostream>

/**
 * @brief Gets a line of input from the user
 * @return The input string provided by the user
 */
inline std::string getInput()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

/**
 * @brief Determines the action type from the input string
 * @param input The input string from the user
 * @return 1 for add, 2 for edit, 3 for delete, 4 for exit, -1 for invalid input
 */
int returnInput(std::string input);

/**
 * @brief Extracts the content part from the input string
 * @param input The input string from the user
 * @return The content part after the command
 */
std::string returnContent(std::string input);

/**
 * @brief Extracts the action command from the input string
 * @param input The input string from the user
 * @return The action command (add, edit, del, exit)
 */
std::string getAction(std::string input);

/**
 * @brief Extracts the item number from an edit or delete command
 * @param input The input string from the user
 * @return The item number to edit or delete
 */
int getItemNumber(const std::string input);