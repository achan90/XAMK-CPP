#include <iostream>
#include <string>
#include <regex>

void start(std::string input) {
	std::regex rgxArray[4] = { std::regex("\x84"),std::regex("\x8e"),std::regex("\x94"),std::regex("\x99") };
	std::string strArray[4] = {"a","A","o","O"};

	for (int x = 0; x < 4; x++) {
		if (std::regex_match(input, rgxArray[x]) == true) {
			input = std::regex_replace(input, rgxArray[x], strArray[x]);
		}
	}
	std::cout << std::endl << input << std::endl;
	std::cout << "Syota rivi tekstia: " << std::endl;
	std::getline(std::cin, input);

	for (int x = 0; x < 4; x++) {
		if (std::regex_match(input, rgxArray[x]) == true) {
			start(input);
		}
		else {
			return;
		}
	}
}

int main(void) {
	std::string input;	

	std::cout << "Syota rivi tekstia: " << std::endl;
	std::getline(std::cin, input);

	start(input);

	std::cout << std::endl;
	system("pause");
	return 0;
}