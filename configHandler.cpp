#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

extern std::string separator;
extern std::string nameColour;
extern std::string userName;
int changeColour(std::string colour);

void getConfig() {
	std::ifstream file("config");
	std::string line;
	if (file.is_open()) {
		while(std::getline(file,line)) {
			std::stringstream ss(line);
			std::string arg;
			std::vector<std::string> args;
			while (ss >> arg) {
				args.push_back(arg);
			}
			if (args.size() <= 1) {
				if (args.size() > 1) std::cout << "ERROR WITH CONFIG!! " << args[0] << " is invalid!" << std::endl;
				else continue;
			}
			if (args[0] == "separator") {
				if (!args[1].empty()) {
					if ( args[1] != "ChangeMe!") separator = args[1] + " ";
				}
			}
			else if (args[0] == "defaultNameColour") {
				if (!args[1].empty()) {
					if(args[1] != "ChangeMe!") changeColour(args[1]);
				}
			}
			else if (args[0] == "defaultName") {
				if (!args[1].empty()) {
					if (args[1] != "ChangeMe!") userName = args[1];
				}
			}
		}
	}
	else std::cout << "Config File doesnt exist!" << std::endl;
    file.close();
}
