/*
K�ytt�j� sy�tt�� tekstirivej�.Ohjelma loppuu, kun sy�tetty pelkk� ENTER.
Ohjelma etsii kultakin sy�tetylt� rivilt� merkkijonot "oli" ja poistaa ne.
Kun rivilt� on poistettu kaikki merkkijonot "oli", ohjelma tulostaa j�ljelle j��neen merkkijonon.

Huom.Rivi on mahdollisesti k�yt�v� useita kertoja l�pi, esim.teksti alussa ...ololii,
poistetaan v�liss� oleva "oli", riville j�� ...oli
Tai mahdollisessa silmukassa pit�� palata taaksep�in

Merkkijonon poisto(korvaaminen) katso:
http://www.cplusplus.com/reference/string/string/replace/

Ajoesimerkki:

Anna rivillinen teksti� :
: abc kolix sololiiska kol i
Olit poistettu : abc kx sska kol i
Anna rivillinen teksti� :
: Olikohan string.replace(alkuindex, korvattavien merkkien lukum��r�, "") oliko ?
Olit poistettu : Olikohan string.replace(alkuindex, korvattavien merkkien lukum��r�, "") ko ?
Anna rivillinen teksti� :
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

	std::cout << std::endl << "Anna rivillinen teksti�: ";
	std::getline (std::cin, str);

	while (std::regex_match(str, find)) {
		str = std::regex_replace(str, remove, "");
	}

	std::cout << std::endl << "'olit' poistettu: " << str << std::endl;
	system("pause");

	return 1;
}