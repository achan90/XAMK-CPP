/*
Käyttäjä syöttää sanoja (vähintään 1 merkki).
Jos sanassa on vain 1 merkki, ohjelma ei pyydä enempää sanoja ja tulostaa: "Loppu".
Jos sanassa on vähintään 2 merkkiä, ohjelma vaihtaa sanan 1. ja viimeisen merkin keskenään.
Jos kuitenkin 1. ja viimeinen merkki ovat samoja, ohjelma vaihtaa kyseiset 2 merkkiä '*'-merkeiksi .
Vaihtojen jälkeen ohjelma tulostaa tekstin: "Et tainnut antaa sanaa " ja sen jälkeen muutetun sanan.
Ajoesimerkki:
Anna sana: kissa
Et tainnut antaa sanaa aissk
Anna sana: apina
Et tainnut antaa sanaa *pin*
Anna sana: hevonen
Et tainnut antaa sanaa nevoneh
Anna sana: ab
Et tainnut antaa sanaa ba
Anna sana: x
Loppu
*/

#include <iostream>
#include <string>

int main(void) {
	while (true) {
		std::string word = "";
		std::cout << std::endl << "Anna sana: ";
		std::cin >> word;

		int length = word.length();

		if (length == 1) {
			std::cout << std::endl << "Loppu." << std::endl;
			break;
		}
		else {
			if (word[0] == word[length - 1]) {
				word.replace(0, 1, "*");
				word.replace(length - 1, 1, "*");
				std::cout << std::endl << "Et tainnut antaa sanaa " << word << std::endl;
			}
			else {
				char temp = word[0];
				word[0] = word[length - 1];
				word[length - 1] = temp;

				std::cout << std::endl << "Et tainnut antaa sanaa " << word << std::endl;
			}
		}
	}
	system("pause");
	return 0;
}