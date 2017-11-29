/*
Tee ohjelma, joka pyyt‰‰ k‰ytt‰j‰lt‰ 10 kokonaislukua ja sijoittaa ne 10-alkioiseen taulukkoon. 
Lopuksi ohjelma selvitt‰‰, kuinka monta luvuista oli suurempi kuin 10.
*/

#include <iostream>
#include <string>

int main(void) {
	int array[10];
	int num = 0;

	for (int i = 0; i < 10; i++) {
		std::cout << "Anna numero " << i + 1 << ": ";
		std::cin >> array[i];
	}

	for (int i = 0; i < 10; i++) {
		if (array[i] > 10) {
			num += 1;
		}
	}
	if (num == 1){
		std::cout << std::endl << num << " luku > 10." << std::endl;
	}
	else {
		std::cout << std::endl << num << " lukua > 10." << std::endl;
	}
	system("pause");

	return 0;
}