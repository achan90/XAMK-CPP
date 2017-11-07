#include <iostream>
/*Pekka Pousi

siirto(maara, otan);
pelaaja 3 -> ohjelma 1 -> j�ljell� 17
pelaaja 2 -> ohjelma 2 -> j�ljell� 13
pelaaja 2 -> ohjelma 2 -> j�ljell� 9
pelaaja 19 -> "Otapa uudestaan!" -> Pelaaja 1 -> ohjelma 3 -> j�ljell� 5
pelaaja "yksi" -> "Otapa uudestaan!" -> pelaaja "yksi" -> "Otapa uudestaan!" -> pelaaja 1 -> ohjelma 3 j�ljell� 1
pelaaja 8 -> "Otapa uudestaan!" -> pelaaja 1 -> "H�visit pelin! Paina mita tahansa lopettaaksesi."

*/

//Kertoo siirto() funktion, sek� maara ja otan muuttujien tyypit, main() funktiolle.
void siirto(int maara, int otan);

//Toimii ohjelman l�ht�pisteen�.
int main(void) {
	//M�ritt� tikkujen alkum�r�n.
	int maara = 21;
	int otan = 0;

	//Kertoo pelin idean k�ytt�j�lle.
	std::cout << "Pelin alussa saatavilla on 21 tikkua. Pelaaja ja ohjelma poimivat vuorotellen 1-3 tikkua." << std::endl;
	std::cout << "Se kumpi pakottaa toisen poimimaan viimeisen tikun voittaa pelin." << std::endl << std::endl;

	//Kysyy k�ytt�j�lt� kuinka monta tikkua h�n ottaa.
	std::cout << "Kuinka monta tikkua otat? (1-3) ";
	//Pyyt�� uudet sy�tteet tarpeen vaatiessa.
	while (!(std::cin >> otan)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Otapa uudestaan!" << std::endl;
	}

	//K�ynnist�� funktion.
	siirto(maara, otan);

	return 0;
}


void siirto(int maara, int otan) {
	//Mik�li k�ytt�j� joutuu ottamaan viimeisen tikun, h�vi�� h�n pelin.
	//otan < 4 ehto, est�� peli� p��ttym�st� liian aikaisin (esim vahingossa 22 tikkua ottaessa)
	if (maara - otan < 1 && otan < 4) {
		std::cout << std::endl << "Havisit pelin! Paina ENTER lopettaaksesi." << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
	//Laskee tikkujen t�m�n hetkisen m��r�n ja varmistaa kierroksella poistuvan 4 tikkua, jolloin ohjelma ei voi h�vit�.
	else {
		int uusiMaara = maara - otan;
		int koneOttaa = 4 - otan;

		//Hyv�ksyy ainoastaan kokonaisluvut 1 - 3 pelaajan ottamien tikkujen m��r�ksi.
		if (otan == 1 || otan == 2 || otan == 3) {
			maara = uusiMaara - koneOttaa;

			//Tunnistaa ohjelman "voitto ehdot" ja ratkaisee pelin ohjelman hyv�ksi.
			if (maara == 2 || maara == 3 || maara == 4) {
				if (maara == 2) {
					siirto(maara, 1);
				}
				else if (maara == 3) {
					siirto(maara, 2);
				}
				else if (maara == 4) {
					siirto(maara, 3);
				}
			}
			//Ilmoittaa t�m�n hetkisen tikkujen m��r�n ja uudelleen kutsuu funktion p�ivitetyill� parametreilla.
			else {
				std::cout << std::endl << "Kone otti " << koneOttaa << " Jaljella on: " << maara << std::endl << "Kuinka monta tikkua otat? (1-3) ";
				while (!(std::cin >> otan)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Otapa uudestaan!" << std::endl;
				}
				siirto(maara, otan);
			}
		}
		//Pyyt�� uudet sy�tteet tarpeen vaatiessa.
		else {
			std::cout << "Otapa uudestaan!" << std::endl;
			while (!(std::cin >> otan)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Otapa uudestaan!" << std::endl;
			}
			siirto(maara, otan);
		}
	}
}

//testing 