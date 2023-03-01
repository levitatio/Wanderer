#include "../include/Hero.h"

Hero::Hero(MapTile& mapTilePtr, SDL_Texture& text) : Character(mapTilePtr, text) {
    _maxHP = 21;
    _DP = 4;
    _SP = 6;
    _currentHP = _maxHP;
}


void Hero::moving(DIRECTION direction) {
    /* need more renderable
    switch (direction) {
        case DIRECTION::LEFT  : _texturePtr = gTextures[int(IMAGES::HEROLEFT)]; break;
        case DIRECTION::UP    : _texturePtr = gTextures[int(IMAGES::HEROUP)]; break;
        case DIRECTION::DOWN  : _texturePtr = gTextures[int(IMAGES::HERODOWN)]; break;
        case DIRECTION::RIGHT : _texturePtr = gTextures[int(IMAGES::HERORIGHT)]; break;
    }
    */
    Character::moving(direction);
}
