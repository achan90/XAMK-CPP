#include "stdafx.h" //Visual Studio precompiled headers -> https://www.viva64.com/en/b/0265/
#include <iostream> //cin, cout... -> http://www.cplusplus.com/reference/iostream/
#include <string> //Strings are objects that represent sequences of characters -> http://www.cplusplus.com/reference/string/string/
#include <iomanip> //Header providing parametric manipulators -> http://www.cplusplus.com/reference/iomanip/
#include "Character.h"

using namespace std; //no need to explicitly add std:: before anything that's found from Standard C++ Library -> http://www.cplusplus.com/reference/

bool continueExecution = true;
char userInput[1];

const int mapWidth = 20;
const int mapHeight = 10;

//Enums -> http://www.cplusplus.com/doc/tutorial/other_data_types/
enum Direction {
	North,
	East,
	South,
	West
};

//Arrays-> http://www.cplusplus.com/doc/tutorial/arrays/
string keyCommands[][2]
{
	{ "W", "Move North" },
	{ "A", "Move West" },
	{ "S", "Move South" },
	{ "D", "Move East" },
	{ "Q", "Quit" }
};

string mapCharacters[][2]
{
	{ ".","Road" },
	{ "T","Tree" },
	{ "~", "Plains" },
	{ "^","Mountain" }
};

string map[mapHeight][mapWidth]
{
	//1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20 (0-19)
	{ "^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^" }, //1
	{ "^","^","^","~","~","~","~","^","^","^","~","~","~","~","T","T","T","T","^","^" }, //2
	{ "^",".",".",".","T","~",".",".",".","~","~","~","~","~","~","~","T","T","~","^" }, //3
	{ "^","~","~",".","~","~",".","T",".","~","~","~","~","~","~",".",".",".",".","^" }, //4
	{ "^","^","~",".",".",".",".","~",".","~","~","~","~","~","~",".","~","~","~","^" }, //5
	{ "^","~","~","~","~","~","~","~",".","~","~","~","T","~","~",".","T","~","~","^" }, //6
	{ "^","T","T","~","~","~","~","~",".","~",".",".",".",".",".",".","~","~","~","^" }, //7
	{ "^","^","T","~","~","~","T","~",".",".",".","~","~","~","~","~","~","~","~","^" }, //8
	{ "^","^","T","~","~","~","~","~","~","~","~","~","~","~","~","~","~","^","^","^" }, //9
	{ "^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^","^" }, //10 (0-9)
};

//hero is on object of class character
Character hero("Sepi", 30, 7, 17, 3, mapWidth, mapHeight);

//Is player on the road, plains, mountain or is there a tree where he stands
void PrintPlayerPos() {
	string currentMapSymbolValue = map[hero.MapPosY][hero.MapPosX]; //What's the map character under player's pos?
	int arrOuterLength = sizeof(mapCharacters) / sizeof(mapCharacters[0]);

	for (int i = 0; i < arrOuterLength; i++) {
		if (mapCharacters[i][0] == currentMapSymbolValue) //if 'key' matches...
		{
			cout << mapCharacters[i][1] << "." << endl; //...print 'value'
			break;
		}
	}
}

//List all available commands in a neat 'table'
void ListCommands() {
	cout << left << setw(10) << "Key" << right << setw(20) << "Command" << endl;
	cout << setfill('-') << setw(30) << "-" << endl;

	int arrOuterLength = sizeof(keyCommands) / sizeof(keyCommands[0]);

	cout << setfill('.');  //fill with spaces
	for (int i = 0; i < arrOuterLength; i++) {
		cout << left << setw(10) << keyCommands[i][0] << right << setw(20) << keyCommands[i][1] << endl;
	}
	cout << "\n";
}

void DrawMap() {
	//In outer loop we iterate through our map array's "rows"
	for (int row = 0; row < mapHeight; row++) {
		//...and in inner loop we iterate through columns and print the value for map "cell" to x,y position
		for (int col = 0; col < mapWidth; col++) {
			if (row == hero.MapPosY && col == hero.MapPosX) {
				cout << "@";
			}
			else {
				cout << map[row][col];
			}
		}
		//new line after columns loop
		cout << "\n";
	}
	//Print where player is standing currently
	PrintPlayerPos();
	//new line after map is drawn
	cout << "\n";
}

bool MainMenu() {
	ListCommands();
	DrawMap();

	cout << "What's your next move: ";

	char inputKey;
	cin >> inputKey;
	cin.ignore(256, '\n');

	switch (inputKey) {
	case 'W': case 'w':
		hero.Move(North);
		cout << "You pressed w or W..." << endl;
		break;

	case 'A': case 'a':
		hero.Move(East);
		cout << "You pressed a or A..." << endl;
		break;

	case 'S': case 's':
		hero.Move(South);
		cout << "You pressed s or S..." << endl;
		break;

	case 'D': case 'd':
		hero.Move(West);
		cout << "You pressed d or D..." << endl;
		break;

	case 'Q': case 'q':
		return false;
		break;

	default:
		cout << "Unknown command '" << inputKey << "'." << endl;
		break;
	}
	return true;
}

int main() {
	while (continueExecution)
	{
		//System (in this case Windows) call to clear console. Just to simulate game with one view...		
		system("cls");

		continueExecution = MainMenu();
	}
	return 0;
}