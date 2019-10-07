#ifndef WANDERER_DRAWABLE_H
#define WANDERER_DRAWABLE_H
#include <SDL.h>
#include <ctime>
#include <stdlib.h>

extern const int TILE_UNIT;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Texture* gTextures[];



enum class IMAGES{
    FLOOR, WALL, BOSS, SKELETON, HERODOWN, HEROUP, HEROLEFT, HERORIGHT
};

class Drawable {
public:
    Drawable();
    Drawable(int posX, int posY, IMAGES images);

    void draw(SDL_Renderer* render);
    void setTexture(SDL_Texture* texture);
    SDL_Rect getRect();
    IMAGES getType();
protected:
    SDL_Rect _rect;
    SDL_Texture* _texturePtr;
    IMAGES _type;
};


#endif //WANDERER_DRAWABLE_H
