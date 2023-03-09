#ifndef WANDERER_MONSTER_H
#define WANDERER_MONSTER_H

#include "Character.h"
#include "MapTile.h"

class Monster : public Character{
public:
    Monster(MapTile& , const std::string&);
    Monster(MapTile&, int posX, int posY, const std::string&);
    void moving ();
protected:
};


#endif //WANDERER_MONSTER_H
