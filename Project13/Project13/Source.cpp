/*
Ohjelma lukee käyttäjältä 2 lausetta.
Jos lauseissa on samassa kohdassa(samalla indeksin arvolla) sama numero - merkki,
lauseessa 1 kyseinen merkki korvataan ? -merkillä.
Jos lauseissa on samassa kohdassa(samalla indeksin arvolla) sama muu kuin numero - merkki,
lauseessa 2 kyseinen merkki korvataan "-merkillä.

Ajoesimerkki :

	Anna lause 1 : Maalari maalaa 3 taloa 12 päivässä
	Anna lause 2 : 2 maalaria maalaa talon 2 päivässä, kun aika menee rupatteluun
	Lause1 : Maalari maalaa 3 taloa 1 ? päivässä
	Lause2 : 2 ma"lari" m""laa talon 2""""""""", kun aika menee rupatteluun
	Press any key to continue . . .
*/

#include <iostream>
#include <string>
#include <regex>

void changeSentence(std::string sentence1, std::string sentence2, int length) {
	std::regex num("\\d");
	std::regex chr("\\D");

	for (int count = 0; count < length; count++) {
		if (sentence1[count] == sentence2[count]) {
			std::string str1(1, sentence1[count]);
			std::string str2(1, sentence2[count]);

			if (std::regex_match(str1, num)) {
				sentence1.replace(count, 1, "?");
			}
			else if (std::regex_match(str2, chr)) {
				sentence2.replace(count, 1, "\"");
			}
		}
	}
	std::cout << std::endl << sentence1 << std::endl << sentence2 << std::endl;
}

int main(void) {
	std::string sentence1, sentence2;

	std::cout << "Anna lause 1: ";
	getline(std::cin, sentence1);
	std::cout << "Anna lause 2: ";
	getline(std::cin, sentence2);

	if (sentence1.length() > sentence2.length()) {
		changeSentence(sentence1, sentence2, sentence1.length());
	}
	else {
		changeSentence(sentence1, sentence2, sentence2.length());
	}
	
	system("pause");
	return 0;
}
