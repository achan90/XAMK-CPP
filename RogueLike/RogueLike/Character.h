#pragma once
#include <string>
using namespace std;

class Character {
private:
	int mapWidth;
	int mapHeight;

public:	
	string Name = "Sepi";
	int Hp = 30;
	int Strength = 7;
	int MapPosX = 17;
	int MapPosY = 3;

	Character(string _name, int _hp, int _strength, int _mapPosX, int _mapPosY, int _mapWidth, int _mapHeight);
	
	void Move(int _dir);
};
