#include "../include/Character.h"
#include "../include/Game.h"

Character::Character(MapTile& mapTilePtr, const std::string& filePath) : _currentMapPtr(mapTilePtr), _maxHP(0), _currentHP(0), _DP(0), _SP(0)
{
    _renderable.init(filePath, _transform, Vector2D(80, 80));
}

Character::Character(MapTile& mapTilePtr, int posX, int posY, const std::string& filePath) : _currentMapPtr(mapTilePtr)
{
    _transform.position.x = posX;
    _transform.position.y = posY;
    _renderable.init(filePath, _transform, Vector2D(80, 80));
    /*
    SDL_Log("current posX: %f posY: %f",
            _transform.position.x,
            _transform.position.y);

    */
}

bool Character::isDead() {
    return _currentHP == 0;
}

void Character::setCurrentPosition(int posX, int posY) {
    // SDL_Log("moving");
    _transform.position.x = posX;
    _transform.position.y = posY;

}
void Character::setCurrentPosition(const Vector2D& pos) {

    _transform.position = pos;
}

void Character::moving(DIRECTION direction) {
    Tile* newTile = getMoveDestinationTile(direction);

    if (isPossibleMoving(newTile))
    {
        setCurrentPosition(newTile->getPosition());
    }
}


bool Character::isPossibleMoving(Tile* tile)
{
    if (tile)
    {
        return tile->getType() == IMAGES::FLOOR;
    }

    return false;
}

Tile* Character::getMoveDestinationTile(DIRECTION direction)
{
    float posDeltaX = 0, posDeltaY = 0;

    switch (direction) {
        case DIRECTION::LEFT:
            posDeltaX = -Game::Instance().TILE_UNIT;
            break;
        case DIRECTION::DOWN:
            posDeltaY = +Game::Instance().TILE_UNIT;
            break;
        case DIRECTION::RIGHT:
            posDeltaX = +Game::Instance().TILE_UNIT;
            break;
        case DIRECTION::UP:
            posDeltaY = -Game::Instance().TILE_UNIT;
            break;
        default: break;

    }

    Tile* result = _currentMapPtr.searchTile(_transform.position.x + posDeltaX, _transform.position.y + posDeltaY);
    return result;
}
