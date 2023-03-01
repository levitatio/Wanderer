//
// Created by CFY on 2019. 10. 07..
//

#include "../include/Tile.h"


Tile::Tile(Vector2D position, IMAGES type, SDL_Texture& t)
{
    // SDL_Log("tile constr. text: %p", &t);
    _position = position;
    _type = type;
    _renderable.init(t, position, Vector2D(80, 80));
}
