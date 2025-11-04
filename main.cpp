#include <iostream>
#include <list>
#include <string>
using namespace std;

std::list<string> messList;
string userName;
int nameColour = 37;
std::string separator = ": ";

enum colours {
	red = 31,
	green = 32,
	yellow = 33,
	blue = 34,
	purple = 35,
	cyan = 36,
	white = 37
};

void getConfig();

string getUserName() {
	string returnString;
	std::cout << "user name > ";
	std::getline(cin,returnString);
	return returnString;
}
void showScreen() {
	system("clear");
	std::cout << "Riley's cool C++ messenger test!" << endl;
	for (auto& mess : messList) {
		std::cout << mess <<endl;
	}
}
int changeColour(std::string colour) {
	if (colour == "red") {
		nameColour = red;
		return 0;
	} else if (colour == "green") {
		nameColour = green;
		return 0;
	} else if (colour == "yellow") {
		nameColour = yellow;
		return 0;
	} else if (colour == "blue") {
		nameColour = blue;
		return 0;
	} else if (colour == "purple") {
		nameColour = purple;
		return 0;
	} else if (colour == "cyan") {
		nameColour = cyan;
		return 0;
	} else if (colour == "white") {
		nameColour = white;
		return 0;
	} else if (colour == "ChangeMe!") {
		return 0;
	} else {
  	  string colourIn;
		std::cout << "red, yellow, blue, purple, cyan, white > "; 
		std::getline(cin,colourIn);
		if (colourIn == "red") { return red; }
		else if (colourIn == "green") { return green; }
		else if (colourIn == "yellow") { return yellow; }
		else if (colourIn == "blue") { return blue; }
		else if (colourIn == "purple") { return purple; }
		else if (colourIn == "cyan") { return cyan; }
		else { return 37; }
	}
}
void changeName() {
	string nameNew;
	int invalid = 1;
	while(invalid) {
	std::cout << "insert new name! > ";
	std::getline(cin,nameNew);
	if (nameNew != "" && nameNew != " ") { userName = nameNew; invalid = 0; }
	else std::cout << "invalid name!" << std::endl;
	}
}


int main() {
	system("clear");
	getConfig();
	std::cout << "Riley's cool C++ messenger test!" << endl;
	while(userName.empty()) {
		userName = getUserName();
	}
	string input;
	while(true) {
		int handled = 0;
		std::cout << "\033[" << std::to_string(nameColour) << "m" << userName << "\033[0m > ";
		std::getline(cin,input);
		if (input.contains("!meow")) { 
			messList.push_back("\033[" + std::to_string(nameColour) + "m" + userName + "\033[0m meows 999 times");
            handled = 1;
			showScreen();
		}
		if (input.contains("!colour")) {
			nameColour = changeColour("");
            handled = 1;
            showScreen();
		}
		if (input.contains("!nameChange")) {
			changeName();
			handled = 1;
			showScreen();
		}
		if (!handled) { 
			messList.push_back("\033[" + std::to_string(nameColour) + "m" + userName + "\033[0m" + separator + input);
			showScreen();
		}
	}
	return 0;
}
