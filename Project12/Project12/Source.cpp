/*
Ohjelma etsii sy�terivilt� per�kk�isi� numeroita.Jos l�ytyy 2 per�kk�ist� numeroa, ne tulostetaan omalle rivilleen.
Jos useampia per�kk�isi�, n�ist� ei tulosteta mit��n, ei edes 2 ensimm�ist�.

Ole tarkkana indeksien kanssa.Rivin merkkien indekstit eiv�t saa olla < 0 eik� > rivi.length() - 1

Rivien lukeminen lopetetaan, jos annettu pelkk� enter.

Ajoesimerkki:
Anna rivillinen teksti� :
: abc k12issa 1234 cd 12
12
12
Anna rivillinen teksti� :
: 321 hsk23 s78s cd 123
23
78
Anna rivillinen teksti� :
:
Press any key to continue . .
*/

#include <iostream>
#include <string>
#include <regex>

int main(void) {
	std::regex find("\\D*\\d{2}\\D*");
	std::regex rmvChr("\\D");
	std::regex rmvNum("\\d{3,}");
	std::string str;

	do {
		std::cout << std::endl << "Anna rivillinen teksti�: ";
		std::getline(std::cin, str);
		std::cout << std::endl;
		str = std::regex_replace(str, rmvChr, " ");
		str = std::regex_replace(str, rmvNum, "");
		std::regex_match(str, find);

		for (std::sregex_iterator count = std::sregex_iterator(str.begin(), str.end(), find);
			count != std::sregex_iterator(); ++count) {

			std::smatch match = *count;
			std::string numPair = match.str();
			numPair = std::regex_replace(numPair, rmvChr, "");
			std::string num1(1, numPair[0]);
			std::string num2(1, numPair[1]);

			if (std::stoi(num2) - std::stoi(num1)) {
				std::cout << numPair << std::endl;
			}
		}
	} while (!(str.empty()));

	system("pause");
	return 0;
}