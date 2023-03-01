#ifndef WANDERER_RENDERABLE_H
#define WANDERER_RENDERABLE_H

#include <SDL2/SDL.h>
#include <ctime>
#include <stdlib.h>
#include <vector>

#include "Transform.h"
#include "RenderController.h"

extern const int TILE_UNIT;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Texture* gTextures[];


enum class IMAGES{
    FLOOR, WALL, BOSS, SKELETON, HERODOWN, HEROUP, HEROLEFT, HERORIGHT
};

class Renderable {
public:
    Renderable();
    Renderable(int, int, SDL_Texture&, Vector2D);
    Renderable(const Renderable&);
    ~Renderable();

    void init(SDL_Texture& text, Transform& tr, Vector2D imageSize);
    void init(SDL_Texture& text, Vector2D position, Vector2D imageSize);
    void draw(SDL_Renderer& render);
    void setTexture(SDL_Texture& texture);
    void setTransform(Transform& transform);
    SDL_Rect getRect();
    Transform* _transformPtr;
protected:
    SDL_Texture* _texturePtr;
    // Transform* _transformPtr;
    SDL_Rect _rect;

    Vector2D _imageSize;
    int _indexZ = 0;
};

#endif //WANDERER_RENDERABLE_H
