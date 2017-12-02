#include <iostream>
#include <string>

//  ä = \x84 | ö = \x94 
void process(std::string str, std::string option);
void start(void) {
	std::string str;
	std::string option;

	while (!(option == "q" || option == "Q" || option == "e" || option == "E" || option == "d" || option == "D")) {
		std::cout << "Press e to encrypt a message, d to decrypt a message or q to quit the program: ";
		std::getline(std::cin, option);
	}
	if (option == "q" || option == "Q") {
		return;
	}
	else {
		std::cout << "Please enter the message: ";
		std::getline(std::cin, str);
		process(str, option);
	}
}

void process(std::string str, std::string option) {
	std::string new_str;
	char plain[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
		'w', 'x', 'y', 'z', 'å', '\x84', '\x94' };
	char encrypted[] = { 'e', 'n', 'u', 'c', 'z', 'k', 'p', 'x', 'o', 'r', 'j',
		't', 'd', 'å', 'l', 'w', 'g', 's', 'b', '\x94', 'h', 'a',
		'y', 'q', '\x84', 'i', 'v', 'm', 'f' };

	if (option == "e" || option == "E") {
		for (int i = 0; i < str.length(); i++) {
			int s = i;
			for (int i = 0; i < sizeof(plain) / sizeof(*plain); i++) {
				if (str[s] == plain[i]) {
					new_str += encrypted[i];
				}
			}
		}
	}
	else if (option == "d" || option == "D") {
		for (int i = 0; i < str.length(); i++) {
			int s = i;
			for (int i = 0; i < sizeof(encrypted) / sizeof(*encrypted); i++) {
				if (str[s] == encrypted[i]) {
					new_str += plain[i];
				}
			}
		}
	}
	std::cout << new_str << std::endl << std::endl;
	start();
}

int main(void) {
	start();
	return EXIT_SUCCESS;
}