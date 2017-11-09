#include <iostream>
#include <string>
#include <regex>

int main(void) {
	std::string input;
	std::string output;
	std::regex rgx1("ä");
	std::regex rgx2("Ä");
	
	while (true) {
		std::cout << std::endl << "Syota rivi tekstia: ";
		std::getline(std::cin, input);
		output = std::regex_replace(input, rgx1, "a");
		output = std::regex_replace(input, rgx2, "A");
		std::cout << std::endl << output << std::endl;

		if (!(std::regex_match(input, rgx1))) {
			if (!(std::regex_match(input, rgx2))) {
				break;
			}
		}
	}
	system("pause");
	return 0;
}