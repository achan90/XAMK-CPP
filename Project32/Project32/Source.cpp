#include <iostream>
#include <string>

void lueLuvut(int array[]) {
	for (int i = 0; i < 10; i++) {
		std::cout << "Anna numero " << i + 1 << ": ";
		std::cin >> array[i];
	}
}

void selvita10(int array[]) {
	int num = 0;

	for (int i = 0; i < 10; i++) {
		if (array[i] > 10) {
			num += 1;
		}
	}
	if (num == 1) {
		std::cout << std::endl << num << " luku > 10." << std::endl;
	}
	else {
		std::cout << std::endl << num << " lukua > 10." << std::endl;
	}
}

void tulosta(int array[]) {
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
}

int main(void) {
	int array[10];

	lueLuvut(array);
	selvita10(array);
	tulosta(array);

	std::cout << std::endl;
	std::cout << std::endl;

	system("pause");
	return 0;
}