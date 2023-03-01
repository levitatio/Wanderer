#ifndef WANDERER_MapTile_H
#define WANDERER_MapTile_H

#include <vector>
#include "Tile.h"

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
    MapTile(SDL_Texture& wall, SDL_Texture& floor);

    void createMap();
    void renderMap(SDL_Renderer* render);
    Tile* searchTile(float, float);
protected:
    std::vector<Tile> _tiles;

    SDL_Texture* _wall;
    SDL_Texture* _floor;
};


#endif //WANDERER_MapTile_H
