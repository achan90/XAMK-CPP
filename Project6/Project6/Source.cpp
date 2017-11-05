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
#include <regex>


int start(void) {
	std::string word = "";
	std::cout << std::endl << "Anna sana: ";
	std::cin >> word;

	int length = word.length();

	return length;
}



int main(void) {
	start();
	std::cout << std::endl << start() << std::endl;

	if (start() == 1) {
		std::cout << std::endl << "Loppu." << std::endl;
		system("pause");
		return 0;



	}

}