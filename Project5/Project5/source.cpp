/* 
- Ohjelma pyytää käyttäjältä kokonaislukua väliltä [minLuku, maxLuku]
  (katso esimerkkituloste). 
- Oletetaan, että käyttäjä syöttää aina kokonaisluvun.
- Jos käyttäjä ei anna lukua pyydetyltä väliltä, ohjelma tulostaa 
  syötetyn luvun ja tekstin, ettei luku ollut pyydetyllä välillä
  (katso esimerkkituloste)
- Jos käyttäjän syöttämä luku oli pyydetyllä välillä, ohjelmassa (funktiossa "onkoSama") 
  arvotaan kokonaisluku väliltä [minLuku, maxLuku] ja verrataan  
  käyttäjän syöttämää lukua arvottuun lukuun. 
    -    Jos syötetty oli sama kuin arvottu, 
	     ohjelmassa tulostetaan teksti: "Osuit oikeaan. Tulos: osumat/arvatut", 
		 missä "osumat" on numeroarvo, kuinka monta kertaa tähän mennessä syötetty ja 
		 arvottu luku ovat olleet samoja ja "arvatut" on kokonaislukumäärä, kuinka monta 
		 kertaa käyttäjä on syöttänyt sallitun arvon.
    -    Jos syötetty ei ollut sama kuin arvottu,
	     ohjelmassa tulostetaan teksti: "Ei osunut. Tulos: osumat/arvatut", 
		 missä "osumat" on numeroarvo, kuinka monta kertaa tähän mennessä syötetty ja 
		 arvottu luku ovat olleet samoja ja "arvatut" on kokonaislukumäärä, kuinka monta 
		 kertaa käyttäjä on syöttänyt sallitun arvon.

Ohessa on pohjaohjelma, jonka main-funktio sinun pitäisi toteuttaa. Ohjelmassa käytetään 
apuna funktiota "onkoSama", jonka toteutus on ennen funktiota.

Ohjelma käyttää avukseen kahta funktioiden ulkopuolella määriteltyä
vakiota "minLuku" ja "maxLuku". Käytä ohjelmassasi kyseisiä vakioita,
kun tarvitset johonkin tietoa pienimmästä ja suurimmasta sallitusta
luvusta.

Määritä pääohjelmaan vakio "arvauksetMaksimi", jolle annat arvoksi 20. Tämä on maksimimäärä,
kuinka monta kertaa käyttäjän annetaan arvata, poislukien arvaukset, jotka eivät olleen 
välillä [minLuku, maxLuku]

OHJELMAN AJOESIMERKKI

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/1

Arvaa luku väliltä [1-3]: 0
Luku 0 ei ole väliltä [1-3]

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/2

Arvaa luku väliltä [1-3]: 4
Luku 4 ei ole väliltä [1-3]

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/3

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/4

Arvaa luku väliltä [1-3]: -1
Luku -1 ei ole väliltä [1-3]

Arvaa luku väliltä [1-3]: 5
Luku 5 ei ole väliltä [1-3]

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/5

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/6

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/7

Arvaa luku väliltä [1-3]: 2
Ei osunut. Tulos: 0/8

Arvaa luku väliltä [1-3]: 2
Osuit oikeaan. Tulos: 1/9

Arvaa luku väliltä [1-3]: 2
Osuit oikeaan. Tulos: 2/10

Arvaa luku väliltä [1-3]: 1
Ei osunut. Tulos: 2/11

Arvaa luku väliltä [1-3]: 1
Ei osunut. Tulos: 2/12

Arvaa luku väliltä [1-3]: 1
Osuit oikeaan. Tulos: 3/13

Arvaa luku väliltä [1-3]: 1
Osuit oikeaan. Tulos: 4/14

Arvaa luku väliltä [1-3]: 1
Ei osunut. Tulos: 4/15

Arvaa luku väliltä [1-3]: 3
Osuit oikeaan. Tulos: 5/16

Arvaa luku väliltä [1-3]: 3
Ei osunut. Tulos: 5/17

Arvaa luku väliltä [1-3]: 3
Ei osunut. Tulos: 5/18

Arvaa luku väliltä [1-3]: 3
Ei osunut. Tulos: 5/19

Arvaa luku väliltä [1-3]: 3
Ei osunut. Tulos: 5/20
Press any key to continue . . .
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
   vakiot, jotka määräävät miltä väliltä käyttäjä voi syöttää
   arvoja [minLuku, maxLuku] ja miltä väliltä "onkoSama" funktio arpoo luvun.
   Näitä voidaan käyttää main-funktiossa aivan samoin kuin ne olisi määritelty
   mainin sisällä.
*/
const int minLuku = 1;
const int maxLuku = 3;

/* onkoSama-funktio palauttaa true, jos argumentissa tuleva luku on 
   yhtäsuuri kuin funktiossa arvottu luku. Muussa tapauksessa
   funktio palauttaa false
   Käyttö: 
			if (onkoSama(2)) {
				// se koodi, joka kertoo, että osuttiin oikeaan
			}
			else 
			{
				// se koodi, joka kertoo, että ei osuttu oikeaan
			}
*/

bool onkoSama(int luku) {
	int arvottu;

	srand(time(0));
	arvottu = minLuku + rand() % (maxLuku - minLuku + 1);
	if (luku == arvottu)
		return true;
	else
		return false;
}

int main() {
	int arvauksetMaksimi = 0;
	int tulos = 0;
	int luku = 0;

	while (arvauksetMaksimi < 20) {
		cout << endl << "Arvaa luku valilta [1-3]: ";
		cin >> luku;

		if (luku < minLuku || luku > maxLuku) {
			cout << luku << " ei ole valilta [1-3]" << endl;
		}
		else if (onkoSama(luku) == true) {
			tulos += 1;
			arvauksetMaksimi += 1;

			cout << "Osuit oikeaan. Tulos: " << tulos << "/" << arvauksetMaksimi << endl;
		}
		else if (onkoSama(luku) == false) {
			arvauksetMaksimi += 1;

			cout << "Ei osunut. Tulos: " << tulos << "/" << arvauksetMaksimi << endl;
		}
	}

	cout << endl;
	system("pause");

	return 0;
}