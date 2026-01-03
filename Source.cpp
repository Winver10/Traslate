#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/stat.h>
#endif

#include "getInput.hxx"

class ToDoListApp {
private:
    std::vector<std::string> list;
    std::string filePath;

public:
    ToDoListApp() {
        filePath = getUserProfilePath();
        loadToDoList();
        
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
#endif
    }

    std::string getUserProfilePath() {
#ifdef _WIN32
        char* userProfilePath = getenv("USERPROFILE");
        if (userProfilePath) {
            return std::string(userProfilePath) + "\\Documents\\ToDoList.txt";
        } else {
            std::cerr << "Error: USERPROFILE environment variable not found." << std::endl;
            exit(EXIT_FAILURE);
        }
#else
        char* homePath = getenv("HOME");
        if (homePath) {
            return std::string(homePath) + "/Documents/ToDoList.txt";
        } else {
            std::cerr << "Error: HOME environment variable not found." << std::endl;
            exit(EXIT_FAILURE);
        }
#endif
    }

    void loadToDoList() {
        std::ifstream inFile(filePath);
        if (inFile.is_open()) {
            std::string line;
            while (std::getline(inFile, line)) {
                if (!line.empty()) {
                    list.push_back(line);
                }
            }
            inFile.close();
        }
    }

    void saveToDoList() {
        std::ofstream outFile(filePath);
        if (outFile.is_open()) {
            for (const auto& item : list) {
                outFile << item << std::endl;
            }
            outFile.close();
            std::cout << "OK, I remember what you changed." << std::endl;
        } else {
            std::cerr << "There was an unluky thing happening. I can't save what you changed." << std::endl;
        }
    }

    void displayList() {
        if (list.empty()) {
            std::cout << "Your To-Do List is empty." << std::endl;
            return;
        }
        std::cout << "Your To-Do List:" << std::endl;
        for (size_t i = 0; i < list.size(); ++i) {
            std::cout << i + 1 << ". " << list[i] << std::endl;
        }
    }

    void startMenu() {
        std::cout << "How nice a day!" << std::endl;
        std::cout << "You can do many things with me." << std::endl;
        std::cout << "Enter 'add [content]', 'edit [number] [new content]', 'del [number]', or 'exit'." << std::endl;
    }

    void addItem(const std::string& content) {
        if (content.empty()) {
            std::cout << "You need to tell me what to add!" << std::endl;
        } else {
            list.push_back(content);
            saveToDoList();
            std::cout << "OK, I remind you want to do: " << content << std::endl;
        }
    }

    void editItem(int itemNumber, const std::string& newContent) {
        if (itemNumber < 1 || itemNumber > static_cast<int>(list.size())) {
            std::cout << "Are you sure you entered the right number? There is no such item." << std::endl;
            return;
        }

        std::string oldItem = list[itemNumber - 1];
        list[itemNumber - 1] = newContent;
        saveToDoList();
        std::cout << "OK, I changed '" << oldItem << "' to '" << newContent << "'" << std::endl;
    }

    void deleteItem(int itemNumber) {
        if (itemNumber < 1 || itemNumber > static_cast<int>(list.size())) {
            std::cout << "Are you sure you entered the right number? There is no such item." << std::endl;
            return;
        }

        std::string deletedItem = list[itemNumber - 1];
        list.erase(list.begin() + itemNumber - 1);
        saveToDoList();
        std::cout << "OK, I deleted: " << deletedItem << std::endl;
    }

    void run() {
        startMenu();
        bool isRunning = true;

        while (isRunning) {
            displayList();
            std::string input = getInput();
            
            // Convert input to lowercase for easier parsing
            std::string lowerInput = input;
            std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
            
            if (lowerInput.substr(0, 3) == "add") {
                if (input.length() > 4) {
                    addItem(input.substr(4));
                } else {
                    std::cout << "You need to tell me what to add!" << std::endl;
                }
            } else if (lowerInput.substr(0, 4) == "edit") {
                size_t firstSpace = input.find(' ', 5); // Find space after "edit"
                if (firstSpace != std::string::npos) {
                    try {
                        int itemNumber = std::stoi(input.substr(5, firstSpace - 5));
                        std::string newContent = input.substr(firstSpace + 1);
                        editItem(itemNumber, newContent);
                    } catch (...) {
                        std::cout << "Are you sure you entered a valid number? I can't understand you." << std::endl;
                    }
                } else {
                    std::cout << "Please specify the item number and new content to edit." << std::endl;
                }
            } else if (lowerInput.substr(0, 3) == "del") {
                if (input.length() > 4) {
                    try {
                        int itemNumber = std::stoi(input.substr(4));
                        deleteItem(itemNumber);
                    } catch (...) {
                        std::cout << "Are you sure you entered a valid number? I can't understand you." << std::endl;
                    }
                } else {
                    std::cout << "Please specify the item number to delete." << std::endl;
                }
            } else if (lowerInput.substr(0, 4) == "exit") {
                isRunning = false;
                std::cout << "Goodbye! Have a nice day!" << std::endl;
            } else {
                std::cout << "Invalid command. Please enter 'add', 'edit', 'del', or 'exit'." << std::endl;
            }
        }
    }
};

int main() {
    ToDoListApp app;
    app.run();
    return 0;
}