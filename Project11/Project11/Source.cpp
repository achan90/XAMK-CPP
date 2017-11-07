/*
Käyttäjä syöttää tekstirivejä.Ohjelma loppuu, kun syötetty pelkkä ENTER.
Ohjelma etsii kultakin syötetyltä riviltä merkkijonot "oli" ja poistaa ne.
Kun riviltä on poistettu kaikki merkkijonot "oli", ohjelma tulostaa jäljelle jääneen merkkijonon.

Huom.Rivi on mahdollisesti käytävä useita kertoja läpi, esim.teksti alussa ...ololii,
poistetaan välissä oleva "oli", riville jää ...oli
Tai mahdollisessa silmukassa pitää palata taaksepäin

Merkkijonon poisto(korvaaminen) katso:
http://www.cplusplus.com/reference/string/string/replace/

Ajoesimerkki:

Anna rivillinen tekstiõ :
: abc kolix sololiiska kol i
Olit poistettu : abc kx sska kol i
Anna rivillinen tekstiõ :
: Olikohan string.replace(alkuindex, korvattavien merkkien lukumäärä, "") oliko ?
Olit poistettu : Olikohan string.replace(alkuindex, korvattavien merkkien lukumäärä, "") ko ?
Anna rivillinen tekstiõ :
:
Press any key to continue . . .
*/

#include <iostream>
#include <string>
#include <regex>

int main(void) {
	std::regex find(".*oli.*");
	std::regex remove("oli");
	std::string str;

	std::cout << std::endl << "Anna rivillinen tekstiä: ";
	std::getline (std::cin, str);

	while (std::regex_match(str, find)) {
		str = std::regex_replace(str, remove, "");
	}

	std::cout << std::endl << "'olit' poistettu: " << str << std::endl;
	system("pause");

	return 1;
}