/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon. 
Lisäksi ohjelma pyytää yhden kokonaisluvun ”etsittava” ja ohjelma selvittää, löytyykö ”etsittava” taulukosta. 
Jos löytyy se poistetaan ja kaikkia ”etsittava”:n  jälkeen tulevia taulukon alkioita siirretään yksi elementti kohti 0-elementtiä. 
Taulukon loppuun sijoitetaan arvo 0.  
Lopuksi taulukko tulostetaan.
*/

#include <iostream>
#include <string>

int main(void) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	int num = 0;
	int index = 0;
	bool check = false;

	std::cout << "Anna etsittava numero: ";
	std::cin >> num;

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
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}