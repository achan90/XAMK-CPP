#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <array>


constexpr int array_size = 9;

void print_numbers(std::array<int, array_size> array) {
	std::cout << "Arvottu: ";

	for (int i = 0; i < array_size; i++) {
		if (i == array_size - 1) {
			std::cout << array[i];
		}
		else {
			std::cout << array[i] << ", ";
		}
	}
	std::cout << std::endl << std::endl;

	return;
}

void print_diagram(std::array<int, array_size> array) {
	int count = 10;

	while (count > 0) {
		for (int i = 0; i < array_size; i++) {
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
	for (int i = 1; i < array_size + 1; i++) {
		std::cout << i << "   ";
	}
	return;
}

std::array<int, array_size> create_array(void) {
	std::array<int, array_size> array;

	for (int i = 0; i < array_size; i++) {
		array[i] = rand() % 10 + 1;
	}
	return array;
}

int main(void) {
	auto array = create_array();
	std::string str;
	std::srand(std::time(0));

	while (true) {
		print_numbers(array);
		print_diagram(array);
		std::cout << std::endl << "Again? (yes = y): ";
		std::getline(std::cin, str);
		std::cout << std::endl;

		if (!(str == "y" || str == "Y")) {
			break;
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}