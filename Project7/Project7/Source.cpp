#include <iostream>
#include <array>
#include <string>
#include <limits>

std::array<double, 2> selectNumber(void) {
	double num1 = 0;
	double num2 = 0;

	std::cout << std::endl << "Anna 1. Luku valilta [0,5]: ";
	std::cin >> num1;
	while (num1 > 5 || num1 < 0) {
		std::cout << "Luku ei ole valilta [0,5]" << std::endl << "Anna molemmat luvut uudelleen." << std::endl;
		std::cout << std::endl << "Anna 1. Luku valilta [0,5]: ";
		std::cin >> num1;
	}
	std::cout << "Anna 2. Luku valilta [0,5]: ";
	std::cin >> num2;
	if (num2 > 5 || num2 < 0) {
		std::cout << "Luku ei ole valilta [0,5]" << std::endl << "Anna molemmat luvut uudelleen." << std::endl;
		selectNumber();
	}
	return std::array<double, 2>{num1, num2};
}
 
 std::string whatTodo(void) {
	 std::string choice = "";

	 while (1) {
		 std::cout << std::endl << "* ...Kertolasku" << std::endl;
		 std::cout << "/ ...Jakolasku" << std::endl;
		 std::cout << "L / l ...Lopeta" << std::endl;
		 std::cin >> choice;
		 std::cout << "Valintasi: " << choice << std::endl << std::endl;

		 if (choice == "l" || choice == "L" || choice == "*" || choice == "/") {
			 break;
		 }
	 }
	 return choice;
 }

 void runFunctions(void) {
	 auto numbers = selectNumber();
	 auto choice = whatTodo();

	 if (choice == "*") {
		 std::cout << numbers[0] << "*" << numbers[1] << "=" << numbers[0] * numbers[1] << std::endl << std::endl;
	 }
	 else if (choice == "/") {
		 if (numbers[1] == 0) {
			 std::cout << "0:lla ei voi jakaa." << std::endl;
			 runFunctions();
		 }
		 else {
			 std::cout << numbers[0] << "/" << numbers[1] << "=" << numbers[0] / numbers[1] << std::endl << std::endl;
		 }
	 }
	 else if (choice == "L" || choice == "l") {
		 std::cout << std::endl;
	 }
}

 int main(void) {
	 runFunctions();
	 system("pause");

	 return 0;
 }