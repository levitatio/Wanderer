#include "../include/Renderable.h"

Renderable::Renderable() : _texturePtr(nullptr), _transformPtr(nullptr)
{
    _rect.x = 0;
    _rect.y = 0;
    _rect.w = 80;
    _rect.h = 80;

    _imageSize.x = 80;
    _imageSize.y = 80;
}

Renderable::Renderable(int posX, int posY, SDL_Texture& texture, Vector2D imgSize) : _texturePtr(&texture)
{
    _rect.x = posX;
    _rect.y = posY;
    _rect.w = imgSize.x;

    _rect.h = imgSize.y;

    _imageSize = imgSize;
}

Renderable::~Renderable()
{
    rController.remove(*this);
}

void Renderable::draw(SDL_Renderer& render)
{
    if (_texturePtr == nullptr)
    {
        return;
    }

    if (_transformPtr)
    {
        _rect.x = _transformPtr->position.x - _imageSize.x;
        _rect.y = _transformPtr->position.y - _imageSize.y;

        _rect.w = _imageSize.x * _transformPtr->scale.x;
        _rect.h = _imageSize.y * _transformPtr->scale.y;
    }
    else 
    {
        _rect.x = 0;
        _rect.y = 0;

        _rect.w = _imageSize.x;
        _rect.h = _imageSize.y;
    }

    SDL_RenderCopy(&render, _texturePtr, NULL, &_rect);
}

void Renderable::setTexture(SDL_Texture& texture)
{
    _texturePtr = &texture;

    rController.add(*this);
}

void Renderable::setTransform(Transform &transform)
{
    _transformPtr = &transform;
}

SDL_Rect Renderable::getRect()
{
    return _rect;
}
