// CrappyGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool continue_execution = true;
char user_input[1];

enum direction {
	North,
	East,
	South,
	West
};

void move(direction dir) {
	std::cout << std::endl << "You moved -> " << dir << "." << std::endl;
}

bool main_menu(void) {
	std::cout << std::endl << "What's your next move? ";

	char input_key;
	std::cin >> input_key;
	std::cin.ignore(256, '\n');

	switch (input_key) {
		case 'W':
		case 'w':
			move(North);
			std::cout << "You pressed '" << input_key << "'..." << std::endl;
		break;

		case 'A':
		case 'a':
			move(West);
			std::cout << "You pressed '" << input_key << "'..." << std::endl;
		break;

		case 'S':
		case 's':
			move(South);
			std::cout << "You pressed '" << input_key << "'..." << std::endl;
		break;

		case 'D':
		case 'd':
			move(East);
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

