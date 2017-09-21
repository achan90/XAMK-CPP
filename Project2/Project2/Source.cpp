#include <iostream>
// Pekka Pousi & ??
/*
*/

void priceCheck(int wallet, int price) {
	if (wallet > price) {
		std::cout << "Euroja: " << wallet << std::endl << "Jäätelön hinta: " << price << std::endl << "Osta jäätelö, rahaa jää " << wallet - price << " euroa.";
		std::cin.ignore();
		std::cin.get();
	}
	else {
		std::cout << "Euroja: " << wallet << std::endl << "Jäätelön hinta: " << price << std::endl << "Paastoa!";
		std::cin.ignore();
		std::cin.get();
	}
}

int main(void) {
	int wallet = 0;
	int price = 0;

	std::cout << "Kuinka monta euroa lompakossasi on?" << std::endl;
	while (!(std::cin >> wallet)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Anna euromäärä numeroina." << std::endl;
	}

	std::cout << "Mikä on jäätelön hinta?" << std::endl;
	while (!(std::cin >> price)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Anna hinta numeroina." << std::endl;
	}
	
	priceCheck(wallet, price);

	return 0;
}


