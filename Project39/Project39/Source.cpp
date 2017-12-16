#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <array>

constexpr int array_size = 10;
int count = 0;
std::array<int, array_size> array;

int get_num(void) {
	int num = 0;
	
	std::cout << std::endl << "Enter number between 11 and 20: ";;
	std::cin >> num;
	
	return num;
}

int check_num(int num) { 
	int val = 2;

	for (int i = 11; i < 21; i++) {
		if (num == i) {
			val = 0;
		}
	}
	if (val < 2) {
		for (int i = 0; i < array_size; i++) {
			if (num == array[i]) {
				val = 1;
			}
		}
	}
	if (val < 2) {
		array[count] = num;
		count++;
	}
	std::cout << val << std::endl;
	return val;
}

std::array<int, array_size> sort_array(std::array<int, array_size> array) {
	std::sort(std::begin(array), std::end(array), std::greater<int>());
	return array;
}

int main(void) {
	while (true) {
		auto val = check_num(get_num());

		if (val == 1 || count == 10) {
			break;
		}
	}
	std::array<int, array_size> num_array = sort_array(array);

	for (int i = 0; i < array_size; i++) {
		if (!(num_array[i] == 0))
			std::cout << num_array[i] << " ";
	}
	std::cout << std::endl << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}
