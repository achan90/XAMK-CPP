#include <iostream>
/*Pekka Pousi

siirto(maara, otan);
pelaaja 3 -> ohjelma 1 -> jäljellä 17
pelaaja 2 -> ohjelma 2 -> jäljellä 13
pelaaja 2 -> ohjelma 2 -> jäljellä 9
pelaaja 19 -> "Otapa uudestaan!" -> Pelaaja 1 -> ohjelma 3 -> jäljellä 5
pelaaja "yksi" -> "Otapa uudestaan!" -> pelaaja "yksi" -> "Otapa uudestaan!" -> pelaaja 1 -> ohjelma 3 jäljellä 1
pelaaja 8 -> "Otapa uudestaan!" -> pelaaja 1 -> "Hävisit pelin! Paina mita tahansa lopettaaksesi."

*/

//Kertoo siirto() funktion, sekä maara ja otan muuttujien tyypit, main() funktiolle.
void siirto(int maara, int otan);

//Toimii ohjelman lähtöpisteenä.
int main(void){
	//Märittä tikkujen alkumärän.
	int maara = 21;
	int otan = 0;

	//Kysyy käyttäjältä kuinka monta tikkua hän ottaa.
	std::cout << "Kuinka monta tikkua otat? (1-3)" << std::endl;
	//Pyytää uudet syötteet tarpeen vaatiessa.
	while (!(std::cin >> otan)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Otapa uudestaan!" << std::endl;
	}
	
	//Käynnistää funktion.
	siirto(maara, otan);

	return 0;
}


void siirto(int maara, int otan) {
	//Mikäli käyttäjä joutuu ottamaan viimeisen tikun, häviää hän pelin.
	//otan < 4 ehto, estää peliä päättymästä liian aikaisin (esim vahingossa 22 tikkua ottaessa)
	if (maara - otan < 1 && otan < 4) {
		std::cout << "Havisit pelin! Paina ENTER lopettaaksesi." << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
	//Laskee tikkujen tämän hetkisen määrän ja varmistaa kierroksella poistuvan 4 tikkua, jolloin ohjelma ei voi hävitä.
	else {
		int uusiMaara = maara - otan;
		int koneOttaa = 4 - otan;

		//Hyväksyy ainoastaan kokonaisluvut 1 - 3 pelaajan ottamien tikkujen määräksi.
		if (otan == 1 || otan == 2 || otan == 3) {
			maara = uusiMaara - koneOttaa;

			//Tunnistaa ohjelman "voitto ehdot" ja ratkaisee pelin ohjelman hyväksi.
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
			//Ilmoittaa tämän hetkisen tikkujen määrän ja uudelleen kutsuu funktion päivitetyillä parametreilla.
			else {
				std::cout << "Kone otti " << koneOttaa << " Jaljella on: " << maara << std::endl << "Kuinka monta tikkua otat? (1-3)" << std::endl;
				while (!(std::cin >> otan)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Otapa uudestaan!" << std::endl;
				}
				siirto(maara, otan);
			}
		}
		//Pyytää uudet syötteet tarpeen vaatiessa.
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