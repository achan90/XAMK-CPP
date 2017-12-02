#include <iostream>
#include <string>
#include <random>
#include <ctime>

bool diagram(void) {
	int array[9];
	int count = 10;
	std::string str;

	for (int i = 0; i < 9; i++) {
		array[i] = rand() % 10 + 1;
	}
	while (count > 0) {
		for (int i = 0; i < 9; i++) {
			if (array[i] >= count) {
				std::cout << "*   ";
			}
			else {
				std::cout << "    ";
			}
		}
		std::cout << std::endl;
		count--;
	}
	for (int i = 1; i < 10; i++) {
		std::cout << i << "   ";
	}
	std::cout << std::endl << "Again? (yes = y): ";
	std::getline(std::cin, str);
	
	if (str == "y" || str == "Y") {
		return false;
	}
	else {
		return true;
	}
}

int main(void) {
	std::srand(std::time(0));

	while (!(diagram()));

	system("pause");
	return EXIT_SUCCESS;
}