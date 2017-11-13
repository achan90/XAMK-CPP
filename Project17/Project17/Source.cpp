#include <iostream>
#include <string>

int main(void){
	std::string str;
	std::string newStr;

	std::cout << std::endl << "Syota rivi tekstia: ";
	std::getline(std::cin, str);

	for (int i = 0; i < str.length(); i++) {
		newStr.insert(0, std::string(1, str[i]));
	}

	std::cout << std::endl << newStr << std::endl;
	system("pause");

	return 0;
}
