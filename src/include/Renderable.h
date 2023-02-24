#ifndef WANDERER_RENDERABLE_H
#define WANDERER_RENDERABLE_H

#include <SDL2/SDL.h>
#include <ctime>
#include <stdlib.h>

#include "Transform.h"
#include "RenderController.h"

extern const int TILE_UNIT;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class RenderController;

class Renderable {
public:
    static RenderController rController;

    Renderable();
    Renderable(int, int, SDL_Texture&, Vector2D);
    ~Renderable();

    void draw(SDL_Renderer& render);
    void setTexture(SDL_Texture& texture);
    void setTransform(Transform& transform);
    SDL_Rect getRect();
protected:
    SDL_Texture* _texturePtr;
    Transform* _transformPtr;
    SDL_Rect _rect;

    Vector2D _imageSize;
    int _indexZ = 0;
};

#endif //WANDERER_RENDERABLE_H
