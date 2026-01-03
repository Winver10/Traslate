#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<Windows.h>
#include "getInput.hxx"
using namespace std;

void DisplayList(const vector<string>& list) {
	if (list.empty()) {
		cout << "Your To-Do List is empty." << endl;
		return;
	}
	cout << "Your To-Do List:" << endl;
	for (size_t i = 0; i < list.size(); ++i) {
		cout << i + 1 << ". " << list[i] << endl;
	}
}

void startMenu() {
	cout << "How nice a day!" << endl;
	cout << "You can do many things with me." << endl;
	cout << "Enter '1' for add, '2' for edit, '3' for delete, and '4' for exit." << endl;
}

string getUserProfilePath() {
	char* userProfilePath = getenv("USERPROFILE");
	if (userProfilePath) {
		return string(userProfilePath) + "\\Documents\\ToDoList.txt";
	} else {
		cerr << "Error: USERPROFILE environment variable not found." << endl;
		exit(EXIT_FAILURE);
	}
}

vector<string>  LaodToDoList() {
	vector<string> list;
	string filePath = getUserProfilePath();
	ifstream inFile(filePath);
	if (inFile.is_open()) {
		string line;
		while (getline(inFile, line)) {
			if (!line.empty()) {
				list.push_back(line);
			}
		}
		inFile.close();
	}
	return list;
}

void saveToDoList(const vector<string>& list) {
	string filePath = getUserProfilePath();
	ofstream outFile(filePath);
	if (outFile.is_open()) {
		for (const auto& item : list) {
			outFile << item << endl;
		}
		outFile.close();
		cout << "OK, I remember what you changed." << endl;
	} else {
		cerr << "There was an unluky thing happening. I can't save what you changed." << endl;
	}
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	startMenu();
	string filePath = getUserProfilePath();
	vector<string> rightInput = { "1", "2", "3", "4" };
	vector<string> list = LaodToDoList();
	bool isRunning = 1;
	string input, content;
	int status, item;
	//while (isRunning) {
	//	DisplayList(list);
	//	string firstInput = getInput();
	//	if (firstInput == "1") {
	//		cout << "What doo you want to do? ";
	//		string newItem = getInput();
	//		list.push_back(newItem);
	//		saveToDoList(list);
	//		cout << "OK, I remind you want to do: " << newItem << endl;
	//	} else if (firstInput == "2") {
	//		if (list.empty()) {
	//			cout << "There is nothing. You can add an item now." << endl;
	//			continue;
	//		}
	//		cout << "Enter the number of item to edit (1-" << list.size() << ")" << endl;
	//		string itemNumber = getInput();
	//		try {
	//			size_t index = stoul(itemNumber) - 1;
	//			if (index < list.size()) {
	//				cout << "The item you want to edit: " << list[index] << endl;
	//				cout << "What do you want to change it to?" << endl;
	//				string newItem = getInput();
	//				list[index] = newItem;
	//				saveToDoList(list);
	//				cout << "OK, I remind you want to do: " << newItem << endl;
	//			} else {
	//				cout << "Are you sure you entered the right number? There is no such item." << endl;
	//			}
	//		}
	//		catch (...) {
	//			cout << "Are you sure you entered a number? I can't understand you." << endl;
	//		}
	//	} else if (firstInput == "3") {
	//		if (list.empty()) {
	//			cout << "There is nothing. You can add an item now." << endl;
	//			continue;
	//		}
	//		cout << "Enter the number of item to delete (1-" << list.size() << ")" << endl;
	//		string itemNumber = getInput();
	//		try {
	//			size_t index = stoul(itemNumber) - 1;
	//			if (index < list.size()) {
	//				string deletItem = list[index];
	//				list.erase(list.begin() + index);
	//				saveToDoList(list);
	//				cout << "OK, I deleted: " << deletItem << endl;
	//			} else {
	//				cout << "Are you sure you entered the right number? There is no such item." << endl;
	//			}
	//		}
	//		catch (...) {
	//			cout << "Are you sure you entered a number? I can't understand you." << endl;
	//		}
	//	} else if (firstInput == "4") {
	//		isRunning = 0;
	//		cout << "Goodbye! Have a nice day!" << endl;
	//	} else {
	//		cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;
	//	}
	//}

	while (isRunning)
	{
		DisplayList(list);
		input = getInput();
		command cmd = returnCommand(input);
		switch (cmd.action)
		{
		case 1:
			if (content.empty())
			{
				cout << "You need to tell me what to add!" << endl;
			}
			else
			{
				list.push_back(cmd.content);
				saveToDoList(list);
				cout << "OK, I remind you want to do: " << cmd.content << endl;
			}
			break;
		case 2:
			if (list.empty())
			{
				cout << "There is nothing. You can add an item now." << endl;
				break;
			
			}
			else
			{
				if (cmd.content.empty() || (!(cmd.indexOfContent > list.size()) || cmd.indexOfContent == -1))
				{
					cout << "Do you think you are doing the thing you want in a right way?" << endl;
				}
				else
				{
					list[cmd.indexOfContent - 1] = cmd.content;
					saveToDoList(list);
					cout << "OK, I remind what you changed it to: " << cmd.content << endl;
				}
			}
			break;
		case 3:
			if (list.empty())
			{
				cout << "There is nothing. You can add an item now." << endl;
			}
			else
			{
				if (!(cmd.indexOfContent > list.size()) || cmd.indexOfContent == -1)
				{
					cout << "Do you think you are doing the thing you want in a right way?" << endl;
				}
				else
				{
					string deletItem = list[cmd.indexOfContent - 1];
					list.erase(list.begin() + cmd.indexOfContent - 1);
					saveToDoList(list);
					cout << "OK, I deleted: " << deletItem << endl;
				}
			}
		case 4:
				isRunning = 0;
				cout << "Goodbye! Have a nice day!" << endl;
				break;
		};
		


	}
	return 0;
}