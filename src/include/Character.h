#ifndef WANDERER_CHARACTER_H
#define WANDERER_CHARACTER_H

#include "MapTile.h"
#include "Renderable.h"

enum class DIRECTION {
    LEFT, UP, RIGHT, DOWN, STAY
};

class Character {
public:
    Character(MapTile& mapTilePtr, const std::string& filePath);
    Character(MapTile& mapTilePtr, int posX, int posY, const std::string& filePath);

    bool isDead ();
    void setCurrentPosition (int posX, int posY);
    void setCurrentPosition (const Vector2D&);
    bool isPossibleMoving(Tile*);
    Tile* getMoveDestinationTile(DIRECTION direction);
    virtual void moving(DIRECTION direction);

    void setRenderable();

protected:
    Renderable _renderable;
    Transform _transform;
    int _maxHP;
    int _currentHP;
    int _DP;
    int _SP;
    MapTile& _currentMapPtr;
};


#endif //WANDERER_CHARACTER_H
