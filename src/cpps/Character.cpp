#include "../include/Character.h"

Character::Character(MapTile* mapTilePtr) : Drawable(), _currentMapPtr(mapTilePtr), _maxHP(0), _currentHP(0), _DP(0), _SP(0) { _type = IMAGES::SKELETON;}

Character::Character(MapTile* mapTilePtr, int posX, int posY, IMAGES typeImage) :Drawable(posX, posY, typeImage), _currentMapPtr(mapTilePtr) {}

bool Character::isDead() {
    return _currentHP == 0;
}

void Character::setCurrentPosition(int posX, int posY) {
    _rect.x = posX;
    _rect.y = posY;
}

void Character::moving(DIRECTION direction) {
    if(!isPossibleMoving(direction)){
        direction = DIRECTION::STAY;
    }
    switch (direction) {
        case DIRECTION::LEFT: setCurrentPosition(_rect.x - TILE_UNIT, _rect.y); break;
        case DIRECTION::UP  : setCurrentPosition(_rect.x, _rect.y - TILE_UNIT); break;
        case DIRECTION::DOWN: setCurrentPosition(_rect.x , _rect.y + TILE_UNIT); break;
        case DIRECTION::RIGHT: setCurrentPosition(_rect.x + TILE_UNIT, _rect.y); break;
        case DIRECTION::STAY : break;
        default : break;
    }
}

bool Character::isPossibleMoving(DIRECTION direction) {

    //
    switch (direction) {
        case DIRECTION::LEFT:
            if (_rect.x - TILE_UNIT < 0 || _currentMapPtr->searchTile(_rect.x - TILE_UNIT, _rect.y )->getType() == IMAGES::WALL) return false;
            break;
        case DIRECTION::UP  :
            if (_rect.y - TILE_UNIT < 0 || _currentMapPtr->searchTile(_rect.x,_rect.y - TILE_UNIT)->getType() == IMAGES::WALL) return false;
            break;
        case DIRECTION::DOWN:
            if (_rect.y + TILE_UNIT > SCREEN_HEIGHT - TILE_UNIT || _currentMapPtr->searchTile(_rect.x ,_rect.y + TILE_UNIT)->getType() == IMAGES::WALL) return false;
            break;
        case DIRECTION::RIGHT:
            if (_rect.x + TILE_UNIT > SCREEN_WIDTH - TILE_UNIT || _currentMapPtr->searchTile(_rect.x + TILE_UNIT, _rect.y)->getType() == IMAGES::WALL) return false;
            break;
        default: return false;
    }
    return true;
}
