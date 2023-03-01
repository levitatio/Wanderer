#include "../include/MapTile.h"

MapTile::MapTile(SDL_Texture& wall, SDL_Texture& floor)
{
    _wall = &wall;
    _floor = &floor;
}

void MapTile::createMap() {

    IMAGES image = IMAGES::FLOOR;
    SDL_Texture* text = nullptr;
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            if (map.at(j).at(i)) {
                text = _wall;
                image = IMAGES::WALL;
            } else {
                text = _floor;
                image = IMAGES::FLOOR;
            }
            // SDL_Log("texture addr: %p", text);
            _tiles.push_back(Tile(Vector2D(i * TILE_UNIT, j * TILE_UNIT), image, *text));
        }
    }
}



Tile* MapTile::searchTile(float x, float y) {

    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
    {
        // SDL_Log("out of bounds");
        return nullptr;
    }

    for (int i = 0; i < _tiles.size(); ++i) {
        if (_tiles.at(i).isInside(x, y))
        {
            return &_tiles.at(i);
        }

    }
    return nullptr;

}

