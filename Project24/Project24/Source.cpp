/*
Tee ohjelma, jossa esitell��n 2 taulukkoa �eka� ja �toka�. 
Molemmat alustetaan esittelyn yhteydess� sis�lt�m��n 10 kokonaislukua. 
Esittele my�s taulukko �kolmas�, jonne mahtuu 20 kokonaislukua. 
Sijoita ohjelmassani taulukkoon �kolmas� ensin taulukon �eka� sis�lt� ja t�m�n per��n taulukon �toka� sis�lt�. 
Tulosta taulukko �kolmas�.
*/

#include <iostream>

int main(void) {
	int array1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int array2[] = { 11,12,13,14,15,16,17,18,19,20 };
	int array3[20];

	for (int i = 0; i < 20; i++) {
		if (i < 10) {
			array3[i] = array1[i];
		}
		else {
			array3[i] = array2[i - 10];
		}
	}
	for (int i = 0; i < 20; i++) {
		std::cout << array3[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}