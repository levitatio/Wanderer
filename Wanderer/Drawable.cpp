#include "Drawable.h"

Drawable::Drawable() : _texturePtr(nullptr), _type(IMAGES::FLOOR) {
    _rect.x = 0;
    _rect.y = 0;
    _rect.w = 80;
    _rect.h = 80;
}

Drawable::Drawable(int posX, int posY, IMAGES images) : _texturePtr(gTextures[int(images)]), _type(images) {
    _rect.x = posX;
    _rect.y = posY;
    _rect.w = 80;
    _rect.h = 80;

}


void Drawable::draw(SDL_Renderer* render) {
    SDL_RenderCopy(render, _texturePtr, NULL, &_rect);
}

void Drawable::setTexture(SDL_Texture* texture) {
    _texturePtr = texture;
}

SDL_Rect Drawable::getRect() {
    return _rect;
}

IMAGES Drawable::getType() {
    return _type;
}
