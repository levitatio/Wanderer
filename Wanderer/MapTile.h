#ifndef WANDERER_MapTile_H
#define WANDERER_MapTile_H

#include <vector>
#include "Drawable.h"

extern const int TILE_UNIT;
const std::vector<std::vector<bool>> map{{0,0,0,1,0,0,0,0,0,0},
                                    {0,0,0,1,0,1,0,1,1,0},
                                    {0,1,1,1,0,1,0,1,1,0},
                                    {0,0,0,0,0,1,0,0,0,0},
                                    {1,1,1,1,0,1,1,1,1,0},
                                    {0,1,0,1,0,0,0,0,0,0},
                                    {0,1,0,1,0,1,1,0,1,0},
                                    {0,0,0,0,0,1,1,0,1,0},
                                    {0,1,1,1,0,0,0,0,1,0},
                                    {0,0,0,1,0,1,1,0,0,0}};



class MapTile {
public:
    MapTile();

    void createMap();
    void renderMap(SDL_Renderer* render);
    Drawable* searchTile (int rectX, int rectY);
protected:
    std::vector<Drawable> _tiles;
};


#endif //WANDERER_MapTile_H
