#include <iostream>
#include <functional>
#include <algorithm>
#include <deque>
#include <regex>

const int columns = 5;
const int rows = 5;

void print_table(int table[]) {
	int row_sum = 0;
	int col_sum = 0;
	int col_num = 0;

	for (int i = 0; i < 25; i++) {
		row_sum += table[i];

		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24) {
			std::cout << table[i] << "   " << row_sum << std::endl;
			row_sum = 0;
		}
		else {
			std::cout << table[i] << "  ";
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		col_num = i;

		for (int i = 0; i < 5; i++) {
			col_sum += table[col_num];
			col_num += 5;
		}
		if (col_sum < 10) {
			std::cout << col_sum << "  ";
			col_sum = 0;
		}
		else {
			std::cout << col_sum << " ";
			col_sum = 0;
		}
	}
}

bool insert(int table[]) {
	int row = 10;
	int column = 10;
	int value = 10;
	int cell = 10;
	std::regex rgx1("[1-9]");
	std::regex rgx2("[0-9]");
	std::string str;

	std::cout << std::endl;

	while (!(std::regex_match(std::to_string(row), rgx1))) {
		std::cout << "Enter row number: ";
		std::cin >> row;
	}
	while (!(std::regex_match(std::to_string(column), rgx1))) {
		std::cout << "Enter column number: ";
		std::cin >> column;
	}
	while (!(std::regex_match(std::to_string(value), rgx2))) {
		std::cout << "Enter number to be placed on chart: ";
		std::cin >> value;
	}
	cell = (row - 1) * columns + (column - 1);
	table[cell] = value;

	std::cout << std::endl << "Press c to continue adding values to table: ";
	std::cin >> str;

	if (str == "c" || str == "C") {
		std::cout << std::endl << std::endl;
		print_table(table);
		return false;
	}
	else {
		std::cout << std::endl << std::endl;
		print_table(table);
		return true;
	}
}

int main(void) {
	int table[rows * columns];

	for (int i = 0; i < rows * columns; i++) {
		table[i] = 1;
	}
	while (!(insert(table)));

	std::cout << std::endl << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}