#ifndef WANDERER_MONSTER_H
#define WANDERER_MONSTER_H

#include "Character.h"
#include "MapTile.h"

class Monster : public Character{
public:
    Monster(MapTile* , SDL_Texture&);
    Monster(MapTile*, int posX, int posY, SDL_Texture&);
    void moving ();
protected:
};


#endif //WANDERER_MONSTER_H
