/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon.
Lis‰ksi ohjelma pyyt‰‰ yhden kokonaisluvun îsijoitettavaî sek‰ toisen kokonaisluvun îindexî.
Huolehdi, ett‰ indeksin arvoksi hyv‰ksyt‰‰n vain arvot 0-9. 
Ohjelma sijoittaa îsijoitettavaî:n taulukkoon kohtaan îindexî, siten, 
ett‰ ensin siirret‰‰n taulukon kaikkia alkioita kohdasta îindexî alkaen yhden alkion verran oikealle eli kohden taulukon loppua. 
Viimeinen alkio heitet‰‰n roskiin.  
Lopuksi taulukko tulostetaan.

- taulukon alustus suoritetaan funktiossa "alusta"
- annaSijoitettava -funktio pyyt‰‰ sijoitettavan ja palauttaa sen kutsujalle
- annaIndex -funktio pyyt‰‰ indeksin arvoa niin kauan, ett‰ se on sallituissa rajoissa ja palauttaa indeksin kutsujalle
- sijoita funktio sijoittaa annetun luvun annettuun paikkaan ja tekee tilaa taulukkoon kuten kuvattu aiemmin

*/


#include <iostream>
#include <string>
#include <regex>
#include <array>
#include <ctime>
#include <random>

const int array_size = 10;

std::array<int, array_size> alusta(void) {
	std::array<int, array_size> array;
	std::srand(time(0));

	for (int i = 0; i < array_size; i++) {
		array[i] = std::rand();
		//array[i] = i;
	}
	return array;
}

int annaSijoitettava(std::string str) {
	int num = 0;

	std::cout << "Anna sijoitettava numero: ";
	std::cin >> num;

	return num;
}

int annaIndex(std::string str) {
	int index = 0;
	std::regex rgx("[0-9]");

	while (!(std::regex_match(str, rgx))) {
		std::cout << std::endl << "Anna indeksin numero: ";
		std::cin >> index;
		str = std::to_string(index);
	}
	return index;
}

std::array<int, array_size> sijoita(std::array<int, array_size> array, int num, int index) {
	for (int i = 9; i > index; i--) {
		array[i] = array[i - 1];
	}
	array[index] = num;

	return array;
}

void tulosta(std::array<int, array_size> array) {
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

int main(void) {
	std::string str;
	auto num = annaSijoitettava(str);
	auto index = annaIndex(str);
	auto array = alusta();

	tulosta(sijoita(array, num, index));

	system("pause");
	return EXIT_SUCCESS;
}