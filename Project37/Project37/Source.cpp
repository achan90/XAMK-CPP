/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon ja
lajittelee taulukon siten, että alkiot ovat taulukossa laskevassa järjestyksessä.
- taulukon alustus suoritetaan funktiossa "alusta"
- lajittelu suoritetaan funktiossa "lajittele"
*/

#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <array>

const int array_size =  10;

std::array<int, array_size> alusta(void) {
	std::array<int, array_size> array;

	for (int i = 0; i < array_size; i++) {
		array[i] = i + 1;
	}
	return array;
}

std::array<int, array_size> lajittele(std::array<int, array_size> array) {
	std::sort(std::begin(array), std::end(array), std::greater<int>());

	return array;
}

void tulosta(std::array<int, array_size> array) {
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
int main(void) {
	auto array = alusta();

	tulosta(lajittele(array));
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}