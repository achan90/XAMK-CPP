#include <iostream>
#include <string>
#include <regex>

void start(void);
void print(std::string);

void start(void) {
	std::string str;
	std::regex rgx1("\\b\\d+\\b");
	std::regex rgx2("\\n\\s");
	std::regex rgx3("\\n.*");

	std::cout << std::endl << "Syota rivi tekstia: ";
	std::getline(std::cin, str);

	if (std::regex_search(str, rgx1) == false) {
		std::cout << str << std::endl;
		return;
	}
	else if (std::regex_search(str, rgx1) == true) {
		str = std::regex_replace(str, rgx1, "\n$&\n");
		str = std::regex_replace(str, rgx2, "\n");
		print(str);
	}
}

void print(std::string str) {
	std::cout << str;
	start();
}

int main(void) {	
	start();
	std::cout << std::endl;
	system("pause");
	return 0;
}





