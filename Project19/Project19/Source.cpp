/*
Tee ohjelma, joka pyyt�� k�ytt�j�lt� 10 kokonaislukua ja sijoittaa ne 10-alkioiseen taulukkoon. 
Lis�ksi ohjelma pyyt�� yhden kokonaisluvun �etsittava� ja ohjelma selvitt��, l�ytyyk� �etsitt�v� taulukosta vai ei. 
Jos l�ytyy, ohjelma tulostaa ��etsittava� loytyy�, muussa tapauksessa tulostetaan ��etsittava� ei loydy�.
*/

#include <iostream>
#include <string>

int main(void) {
	int array[10];
	int num = 0;

	for (int i = 0; i < 10; i++) {
		std::cout << "Anna numero " << i + 1 << ": ";
		std::cin >> array[i];
	}
	std::cout << std::endl << "Anna etsittava numero: ";
	std::cin >> num;

	for (int i = 0; i < 10; i++) {
		if (array[i] == num) {
			std::cout << std::endl << "Etsittava loytyy." << std::endl;
			std::cout << std::endl;

			system("pause");
			return 0;
		}
	}
	std::cout << std::endl << "Etsittava ei loydy." << std::endl;
	std::cout << std::endl;

	system("pause");
	return 0;
}