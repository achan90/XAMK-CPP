#include <iostream>

void check(double min, double max) {
	double num = 0;

	std::cout << "Anna luku valilta " << min << "-" << max << ": ";
	std::cin >> num;

	if (num >= min && num <= max) {
		std::cout << "Annoit " << num << std::endl;
		system("pause");
	}
	else {
		check(min, max);
	}
}

void reverse(double min, double max) {
	double temp;

	temp = min;
	min = max;
	max = temp;

	check(min, max);
}

int main(void) {
	double min = 0;
	double max = 0;
	
	std::cout << "Anna alaraja: ";
	std::cin >> min;

	std::cout << "Anna ylaraja: ";
	std::cin >> max;

	if (min > max) {
		reverse(min, max);
	}
	else {
		check(min, max);
	}

	return 0;
}