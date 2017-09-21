#include <iostream>
// Pekka Pousi & ??
/*
*/

void leapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				std::cout << year << " on karkausvuosi." << std::endl;
				std::cin.ignore();
				std::cin.get();
			}
			else{ 
				std::cout << year << " ei ole karkausvuosi." << std::endl;
				std::cin.ignore();
				std::cin.get();
			}
		}
		else {
			std::cout << year << " on karkausvuosi." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}
	}
	else {
		std::cout << year << " ei ole karkausvuosi." << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
}

int main(void){
	int year = 0;

	std::cout << "Anna vuosiluku:" << std::endl;
	while (!(std::cin >> year)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Anna vuosiluku:" << std::endl;
	}

	leapYear(year);

	return 0;
}