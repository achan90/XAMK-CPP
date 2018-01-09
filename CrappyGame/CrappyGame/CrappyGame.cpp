// CrappyGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool continue_execution = true;
char user_input[1];

bool main_menu(void) {
	std::cout << std::endl << "What's your next move? ";

	char input_key;
	std::cin >> input_key;
	std::cin.ignore(256, '\n');

	switch (input_key) {
		case 'W':
		case 'w':
			std::cout << "You pressed '" << input_key << "'..." << std::endl;
		break;

		case 'A':
		case 'a':
			std::cout << "You pressed '" << input_key << "'..." << std::endl;
		break;

		case 'S':
		case 's':
			std::cout << "You pressed '" << input_key << "'..." << std::endl;
		break;

		case 'D':
		case 'd':
			std::cout << "You pressed '" << input_key << "'..." << std::endl;
		break;

		case 'Q':
		case 'q':
			std::cout << std::endl;
			return false;
		break;

		default:
			std::cout << "Unknown command '" << input_key << "'" << std::endl;
		break;
	}

	return true;
}

int main() {
	while (continue_execution) {
		continue_execution = main_menu();
	}

    return 0;
}

