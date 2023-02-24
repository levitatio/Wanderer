#include "../include/Character.h"

Character::Character(MapTile* mapTilePtr, SDL_Texture& t) : _currentMapPtr(mapTilePtr), _maxHP(0), _currentHP(0), _DP(0), _SP(0) 
{
    _renderable = Renderable();
    _renderable.setTexture(t);
}

Character::Character(MapTile* mapTilePtr, int posX, int posY, SDL_Texture& t) : _currentMapPtr(mapTilePtr) 
{
    _renderable = Renderable(posX, posY, t, Vector2D(80, 80));
}

bool Character::isDead() {
    return _currentHP == 0;
}

void Character::setCurrentPosition(int posX, int posY) {
    _transform.position.x = posX;
    _transform.position.y = posY;
}

void Character::moving(DIRECTION direction) {
    if(!isPossibleMoving(direction)){
        direction = DIRECTION::STAY;
    }
    switch (direction) {
        case DIRECTION::LEFT: setCurrentPosition(_transform.position.x - TILE_UNIT, _transform.position.y); break;
        case DIRECTION::UP  : setCurrentPosition(_transform.position.x, _transform.position.y - TILE_UNIT); break;
        case DIRECTION::DOWN: setCurrentPosition(_transform.position.x , _transform.position.y + TILE_UNIT); break;
        case DIRECTION::RIGHT: setCurrentPosition(_transform.position.x + TILE_UNIT, _transform.position.y); break;
        case DIRECTION::STAY : break;
        default : break;
    }
}

bool Character::isPossibleMoving(DIRECTION direction) {

    //
    switch (direction) {
        case DIRECTION::LEFT:
            if (_transform.position.x - 40 - TILE_UNIT < 0 
                || _currentMapPtr->searchTile(_transform.position.x - 40 - TILE_UNIT, _transform.position.y - 40 )->getType() == IMAGES::WALL)
            {
                return false;
            }
            break;
        case DIRECTION::UP  :
            if (_transform.position.y - 40 - TILE_UNIT < 0 
                || _currentMapPtr->searchTile(_transform.position.x - 40,_transform.position.y - 40 - TILE_UNIT)->getType() == IMAGES::WALL) 
                {
                    return false;
                }
            break;
        case DIRECTION::DOWN:
            if (_transform.position.y - 40 + TILE_UNIT > SCREEN_HEIGHT - TILE_UNIT 
                || _currentMapPtr->searchTile(_transform.position.x - 40 ,_transform.position.y - 40 + TILE_UNIT)->getType() == IMAGES::WALL)
                {
                    return false;
                }
            break;
        case DIRECTION::RIGHT:
            if (_transform.position.x - 40 + TILE_UNIT > SCREEN_WIDTH - TILE_UNIT
                || _currentMapPtr->searchTile(_transform.position.x - 40 + TILE_UNIT, _transform.position.y - 40)->getType() == IMAGES::WALL)
                {
                    return false;
                }
            break;
        default: return false;
    }
    return true;
}
