#include <iostream>
#include <string>
#include <regex>

void start(void);
void checkRegex(std::string);


void start(void) {
	std::string input;

	std::cout << "Syota rivi tekstia: ";
	std::getline(std::cin, input);

	checkRegex(input);
}

void checkRegex(std::string input) {
	bool stop = true;
	std::regex rgxArray[4] = { std::regex("\x84"),std::regex("\x8e"),std::regex("\x94"),std::regex("\x99") };
	std::string strArray[4] = {"a","A","o","O" };

	for (int i = 0; i < 4; i++) {
		if (std::regex_search(input, rgxArray[i]) == true) {
			stop = false;
		}
	}
	for (int i = 0; i < 4; i++) {
		input = std::regex_replace(input, rgxArray[i], strArray[i]);
	}
	std::cout << input << std::endl << std::endl;

	if (stop == true) {
		return;
	}
	start();
}

int main(void) {
	start();
	std::cout << std::endl;
	system("pause");
	return 0;
}