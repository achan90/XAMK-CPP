/*
K�ytt�j� sy�tt�� sanoja (v�hint��n 1 merkki).

Jos sanassa on vain 1 merkki, ohjelma ei pyyd� enemp�� sanoja ja tulostaa: "Loppu".

Jos sanassa on v�hint��n 2 merkki�, ohjelma vaihtaa sanan 1. ja viimeisen merkin kesken��n.

Jos kuitenkin 1. ja viimeinen merkki ovat samoja, ohjelma vaihtaa kyseiset 2 merkki� '*'-merkeiksi .

Vaihtojen j�lkeen ohjelma tulostaa tekstin: "Et tainnut antaa sanaa " ja sen j�lkeen muutetun sanan.

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