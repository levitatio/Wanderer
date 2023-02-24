#ifndef WANDERER_CHARACTER_H
#define WANDERER_CHARACTER_H

#include "MapTile.h"
#include "Renderable.h"

enum class DIRECTION {
    LEFT, UP, RIGHT, DOWN, STAY
};

class Character {
public:
    Character(MapTile* mapTilePtr, SDL_Texture& t);
    Character(MapTile* mapTilePtr, int posX, int posY, SDL_Texture& t);

    bool isDead ();
    void setCurrentPosition (int posX, int posY);
    bool isPossibleMoving(DIRECTION direction);
    virtual void moving(DIRECTION direction);

    void setRenderable();

protected:
    Renderable _renderable;
    Transform _transform;
    int _maxHP;
    int _currentHP;
    int _DP;
    int _SP;
    MapTile* _currentMapPtr;
};


#endif //WANDERER_CHARACTER_H
