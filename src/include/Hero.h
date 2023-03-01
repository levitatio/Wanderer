#ifndef WANDERER_HERO_H
#define WANDERER_HERO_H

#include "Character.h"

class Hero : public Character {
public:
    Hero(MapTile&, SDL_Texture&);
    void setBaseImage();
    void moving(DIRECTION) override;
};


#endif //WANDERER_HERO_H
