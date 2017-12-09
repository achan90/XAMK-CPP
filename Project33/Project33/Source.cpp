#include <iostream>
#include <string>

void lueLuvut(int array[]) {
	for (int i = 0; i < 10; i++) {
		std::cout << "Anna numero " << i + 1 << ": ";
		std::cin >> array[i];
	}
}

bool etsi(int array[]) {
	int num = 0;

	std::cout << std::endl << "Anna etsittava numero: ";
	std::cin >> num;

	for (int i = 0; i < 10; i++) {
		if (array[i] == num) {
			return true;
		}
		else {
			return false;
		}
	}
}

void tulosta(int array[]) {
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
}

int main(void) {
	int array[10];
	lueLuvut(array);
	
	if (etsi(array)) {
		tulosta(array);
		std::cout << std::endl << "Etsittava loytyy." << std::endl;
		std::cout << std::endl;
	}
	else {
		tulosta(array);
		std::cout << std::endl << "Etsittava ei loydy." << std::endl;
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}