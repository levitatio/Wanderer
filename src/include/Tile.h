#ifndef WANDERER_TILE_H
#define WANDERER_TILE_H

#include "Renderable.h"
#include "Vector2D.h"

class Tile
{
    public:
    Tile(Vector2D, IMAGES, SDL_Texture&);

    IMAGES getType() { return _type; }
    Vector2D getPosition() { return _position; }
    bool isInside(float x, float y)
    {
        return x >= _position.x && x < _position.x + TILE_UNIT
                && y >= _position.y && y < _position.y + TILE_UNIT;
    };

    bool isInside(Vector2D& pos) { return isInside(pos.x, pos.y);}

    protected:
    Renderable _renderable;
    Vector2D _position;
    IMAGES _type;
};


#endif //WANDERER_TILE_H
