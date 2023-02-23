#include "../include/MapTile.h"


MapTile::MapTile() {


}

void MapTile::createMap() {
    IMAGES image = IMAGES::FLOOR;
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            if (map.at(j).at(i)) {
                image = IMAGES::WALL;
            } else {
                image = IMAGES::FLOOR;
            }
            Drawable d(i * TILE_UNIT, j * TILE_UNIT, image);
            _tiles.push_back(d);
        }

    }

}

void MapTile::renderMap(SDL_Renderer* render) {
    for (int i = 0; i < _tiles.size() ; ++i) {
        _tiles.at(i).draw(render);
    }
}

Drawable* MapTile::searchTile(int rectX, int rectY) {
    Drawable* result = nullptr;
    for (int i = 0; i < _tiles.size(); ++i) {
        if (_tiles.at(i).getRect().x == rectX && _tiles.at(i).getRect().y == rectY)
            result = &_tiles.at(i);
    }
    return result;
}
