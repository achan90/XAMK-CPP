#include <iostream>
#include <string>
#include <regex>

void start(std::string input) {
	std::regex rgxArray[4] = { std::regex("\x84"),std::regex("\x8e"),std::regex("\x94"),std::regex("\x99") };

	input = std::regex_replace(input, rgxArray[0], "a");
	input = std::regex_replace(input, rgxArray[1], "A");
	input = std::regex_replace(input, rgxArray[2], "ö");
	input = std::regex_replace(input, rgxArray[3], "Ö");

	std::cout << std::endl << input << std::endl;

	std::cout << "Syötä rivi tekstiä: " << std::endl;
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

	std::cout << "Syötä rivi tekstiä: " << std::endl;
	std::getline(std::cin, input);

	start(input);

	std::cout << std::endl;
	system("pause");
	return 0;
}