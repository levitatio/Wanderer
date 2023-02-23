#include "../include/Monster.h"
#include <ctime>

Monster::Monster(MapTile* mapTilePtr) : Character(mapTilePtr, 0,0, IMAGES::SKELETON) {
    _maxHP = 29;
    _DP = 6;
    _SP = 7;
    _currentHP = _maxHP;
}

Monster::Monster(MapTile* mapTilePtr, int posX, int posY) : Character(mapTilePtr, posX, posY, IMAGES::SKELETON) {

}

void Monster::moving() {
    int randomNumber = rand() % 5;
    DIRECTION tempDirection = DIRECTION (randomNumber);

    Character::moving(tempDirection);
}
