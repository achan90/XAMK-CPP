#include <iostream>
#include <string>
#include <regex>

int main(void) {
	std::string str;
	bool check = true;
	
	do {
		std::cout << std::endl << "Syota rivi tekstia: ";
		std::getline(std::cin, str);

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				check = false;
			}
			else if (check == true) {
				check = false;
				str.replace(i, 1, "x");
			}
			else if (check == false) {
				check = true;
			}
		}
		check = true;
		std::cout << str << std::endl;
	} while (!(str.empty()));	
	
	system("pause");
	return 0;
}