#include <iostream>
#include <string>

/*
Lukusarja alkaa luvuilla 0,1,2 ja t‰m‰n j‰lkeen seuraavat luvut ovat aina kolmen edellisen luvun summa: 0,1,2,3,6,11,20,37,...
Kirjoita ohjelma, joka esitt‰‰ 22 ensimm‰ist‰ sarjan lukua. Kolme ensimm‰ist‰ lukua ovat vain alustuksiin ja loput voidaan laskea.
*/

int main(void) {
	int count = 3;
	int num = 0;
	int array[22] = { 0,1,2 };
	std::string numSequence = "0,1,2";

	while (count < 22) {
		int value1 = count - 3;
		int value2 = count - 2;
		int value3 = count - 1;

		num = array[value1] + array[value2] + array[value3];
		array[count] = num;
		numSequence += "," + std::to_string(array[count]);
		count += 1;
	}
	
	std::cout << numSequence << std::endl;
	system("pause");

	return 0;

}