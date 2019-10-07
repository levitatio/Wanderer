#ifndef WANDERER_HERO_H
#define WANDERER_HERO_H

#include "Character.h"

class Hero : public Character {
public:
    Hero(MapTile* mapTilePtr);
    void setBaseImage();
    void moving(DIRECTION direction) override;
};


#endif //WANDERER_HERO_H
