#include "../include/Monster.h"
#include <ctime>

Monster::Monster(MapTile* mapTilePtr, SDL_Texture& t) : Character(mapTilePtr, 0,0, t) {
    _maxHP = 29;
    _DP = 6;
    _SP = 7;
    _currentHP = _maxHP;
}

Monster::Monster(MapTile* mapTilePtr, int posX, int posY, SDL_Texture& t) : Character(mapTilePtr, posX, posY, t) {

}

void Monster::moving() {
    int randomNumber = rand() % 5;
    DIRECTION tempDirection = DIRECTION (randomNumber);

    Character::moving(tempDirection);
}
