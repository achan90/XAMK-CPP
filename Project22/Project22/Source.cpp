/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon. 
Lis‰ksi ohjelma pyyt‰‰ yhden kokonaisluvun îsijoitettavaî sek‰ toisen kokonaisluvun îindexî. 
Huolehdi, ett‰ indeksin arvoksi hyv‰ksyt‰‰n vain arvot 0-9. 
Ohjelma sijoittaa îsijoitettavaî:n taulukkoon kohtaan îindexî, siten, ett‰ ensin siirret‰‰n taulukon kaikkia alkioita kohdasta îindexî alkaen yhden alkion verran oikealle eli kohden taulukon loppua. 
Viimeinen alkio heitet‰‰n roskiin.  
Lopuksi taulukko tulostetaan.
*/

#include <iostream>
#include <string>
#include <regex>

int main(void) {
	std::regex rgx("[0-9]");
	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	int index = 0;
	int num;
	int temp;
	std::string str;
	

	std::cout << "Anna sijoitettava numero: ";
	std::cin >> num;	
	
	while (!(std::regex_match(str, rgx))) {
		std::cout << std::endl << "Anna indeksin numero: ";
		std::cin >> index;
		str = std::to_string(index);
	}
	for (int i = 9; i > index; i--) {		
		array[i] = array[i - 1];
	}
	array[index] = num;

	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}