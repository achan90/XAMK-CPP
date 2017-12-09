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
	std::array<int, 10> array;
	std::srand(std::time(0));
	
	for (int i = 0; i < 10; i++) {
		array[i] = std::rand();
	}
}

int pyydaLuku(void) {
	int num = 0;

	std::cout << "Anna etsittava numero: ";
	std::cin >> num;

	return num;
}

void tulosta(std::array<int, array_size> array) {
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

int main(void) {
	auto num = pyydaLuku();
	auto array = alusta();
	int index = 0;
	bool check = false;	

	for (int i = 0; i < 10; i++) {
		if (array[i] == num) {
			index = i;
			check = true;
		}
	}
	if (check == true) {
		for (int i = index; i < 10; i++) {
			array[i] = array[i + 1];
		}
	}
	if (check == true) {
		array[9] = 0;
	}
	tulosta(array);

	system("pause");
	return EXIT_SUCCESS;
}
