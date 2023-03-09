//
// Created by CFY on 2019. 10. 07..
//

#include "../include/Tile.h"


Tile::Tile(Vector2D position, IMAGES type, const std::string& filePath)
{
    // SDL_Log("tile constr. text: %p", &t);
    _position = position;
    _type = type;
    _renderable.init(filePath, position, Vector2D(80, 80));
}
