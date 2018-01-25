#include "stdafx.h"
#include "Character.h"

Character::Character(string _name, int _hp, int _strength, int _mapPosX, int _mapPosY, int _mapWidth, int _mapHeight) {
	Name = _name;
	Hp = _hp;
	Strength = _strength;
	MapPosX = _mapPosX;
	MapPosY = _mapPosY;
	//map size for Move method
	mapWidth = _mapWidth;
	mapHeight = _mapHeight;
}

void Character::Move(int dir) {
	if (dir == 0 && MapPosY > 0)
		MapPosY--; //one step up
	else if (dir == 3 && MapPosX < mapWidth - 1)
		MapPosX++; //one step right
	else if (dir == 2 && MapPosY < mapHeight - 1)
		MapPosY++; //one step down
	else if (dir == 1 && MapPosX > 0)
		MapPosX--; //one step left	
}