#include <iostream>
// Pekka Pousi
/*
Kuinka monta euroa lompakossasi on?
Mika on jaatelon hinta?
Euroja: 10.5
Jaatelon hinta: 2.75
Osta jaatelo, rahaa jaa 7.75 euroa.

Kuinka monta euroa lompakossasi on?
Mika on jaatelon hinta?
Euroja 0.25
Jaatelon hinta: 2
Paastoa!
*/

void priceCheck(double wallet, double price) {
	if (wallet >= price) {
		std::cout << "Euroja: " << wallet << std::endl << "Jaatelon hinta: " << price << std::endl << "Osta jaatelo, rahaa jaa " << wallet - price << " euroa." << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
	else {
		std::cout << "Euroja: " << wallet << std::endl << "Jaatelon hinta: " << price << std::endl << "Paastoa!" << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
}

int main(void) {
	double wallet = 0;
	double price = 0;

	std::cout << "Kuinka monta euroa lompakossasi on?" << std::endl;
	while (!(std::cin >> wallet)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Anna euromaara numeroina." << std::endl;
	}

	std::cout << "Mika on jaatelon hinta?" << std::endl;
	while (!(std::cin >> price)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Anna hinta numeroina." << std::endl;
	}
	
	priceCheck(wallet, price);

	return 0;
}


