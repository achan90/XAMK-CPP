/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon.
Ohjelma tulostaa suurimman luvuista ja indeksin, mistä se löytyy.
- taulukon alustus suoritetaan funktiossa "alusta"
- "etsiSuurin" -funktiossa etsitään suurin luvuista ja palautetaan suurin luku referenssinä ja indeksi return-lausella.
- tulosta-funktio tulostaa taulukon sisällön
*/

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <array>

const int array_size = 10;

std::array<int, 10> alusta(void) {
	std::array<int, array_size> array;
	std::srand(std::time(0));

	for (int i = 0; i < 10; ++i) {
		array[i] = rand();
	}
	return array;
}

int etsiSuurin(std::array<int, array_size> array) {
	int index = 0;
	int num = 0;

	for (int i = 0; i < 10; i++) {
		if (array[i] > num) {
			num = array[i];
			index = i;
		}
	}
	return index;
}

void tulosta(std::array<int, array_size> array) {
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main(void) {
	auto array = alusta();
	tulosta(array);
	auto index = etsiSuurin(array);
	auto num = array[index];
	
	std::cout << "Suurin luvuista on: '" << num << "' ja se loytyy indeksista: '" << index << "'";
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}