#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

int main(void) {
	int num = 0;
	int count = 0;
	int array1[10] = { 0 };
	int array2[10] = { 11,12,13,14,15,16,17,18,19,20 };
	bool check = false;

	while (array1[9] == 0) {
		std::cout << std::endl << "Enter number between 11 and 20: ";;
		std::cin >> num;

		for (int i = 0; i < 10; i++) {
			if (num == array2[i]) {
				check = true;
			}
		}

		for (int i = 0; i < 10; i++) {
			if (num == array1[i]) {
				check = false;
			}
		}
		if (check == true) {
			array1[count] = num;
			count++;
		}
		else if (check == false) {
			std::cout << std::endl << "Number not in range or already used.";
		}
	}
	std::cout << std::endl;

	std::sort(array1, array1 + 10, std::greater<int>());

	for (int i = 0; i < 10; i++) {
		std::cout << array1[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}
