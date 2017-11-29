/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon. 
Ohjelma tulostaa suurimman luvuista ja indeksin, mistä se löytyy.
*/

#include <iostream>
#include <string>

int main(void) {
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int index = 0;
	int num = 0;

	for (int i = 0; i < 10; i++) {
		if (array[i] > num) {
			num = array[i];
			index = i;
		}
	}
	std::cout << "Suurin luvuista on: '" << num << "' ja se loytyy indeksista: '" << index << "'";
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}