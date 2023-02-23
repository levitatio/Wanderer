#ifndef WANDERER_CHARACTER_H
#define WANDERER_CHARACTER_H

#include "Drawable.h"
#include "MapTile.h"

enum class DIRECTION {
    LEFT, UP, RIGHT, DOWN, STAY
};

class Character : public Drawable {
public:
    Character(MapTile* mapTilePtr);
    Character(MapTile* mapTilePtr, int posX, int posY, IMAGES);

    bool isDead ();
    void setCurrentPosition (int posX, int posY);
    bool isPossibleMoving(DIRECTION direction);
    virtual void moving(DIRECTION direction);

protected:
    int _maxHP;
    int _currentHP;
    int _DP;
    int _SP;
    MapTile* _currentMapPtr;
};


#endif //WANDERER_CHARACTER_H
