/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon.
Lis�ksi ohjelma pyyt�� yhden kokonaisluvun �etsittava� ja ohjelma selvitt��, l�ytyyk� �etsittava� taulukosta.
Jos l�ytyy se poistetaan ja kaikkia �etsittava�:n  j�lkeen tulevia taulukon alkioita siirret��n yksi elementti kohti 0-elementti�.
Taulukon loppuun sijoitetaan arvo 0.
Lopuksi taulukko tulostetaan.
- taulukon alustus suoritetaan funktiossa "alusta"
- etsitt�v� luku luetaan omassa funktiossaan "pyydaLuku", joka palauttaa saamansa luvun
- etsi-funktio selvitt��, l�ytyyk� luku taulukosta ja palauttaa indeksin, mist� l�ytyy tai palauttaa taulukon koon tai -1:n.
- poista-funktio poistaa luvun ja siirt�� per�ss� olevia kohti poistettua ja t�ytt�� viimeisen paikan 0:lla
- tulosta-funktio tulostaa taulukon sis�ll�n
*/


#include <iostream>
#include <string>
#include <random>
#include <array>
#include <ctime>

const int array_size = 10;

std::array<int, array_size> alusta(void) {
	std::array<int, array_size> array;
	std::srand(std::time(0));

	for (int i = 0; i < array_size; i++) {
		array[i] = std::rand();
		//array[i] = i;
	}
	return array;
}

int pyydaLuku(void) {
	int num = 0;

	std::cout << "Anna etsittava numero: ";
	std::cin >> num;

	return num;
}

int etsi(std::array<int, array_size> array, int num) {
	int index = 0;

	for (int i = 0; i < array_size; i++) {
		if (array[i] == num) {
			index = i;
			return index;
		}
	}
	return -1;
}

std::array<int, array_size> poista(std::array<int, array_size> array, int index) {
	for (int i = index; i < array_size; i++) {
		if (i == array_size - 1) {
			array[array_size - 1] = 0;
		}
		else {
			array[i] = array[i + 1];
		}
	}
	return array;
}

void tulosta(std::array<int, array_size> array) {
	for (int i = 0; i < array_size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

int main(void) {
	auto num = pyydaLuku();
	auto array = alusta();

	etsi(array, num);
	tulosta(poista(array, num));

	system("pause");
	return EXIT_SUCCESS;
}