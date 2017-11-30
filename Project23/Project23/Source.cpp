//Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon ja lajittelee taulukon siten, että alkiot ovat taulukossa laskevassa järjestyksessä.

#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

int main(void) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	int newArray[10];
	int temp;

	std::sort(array, array + 10, std::greater<int>());

	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}