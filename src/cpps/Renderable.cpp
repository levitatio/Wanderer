#include "../include/Renderable.h"
#include "../include/Game.h"
#include "SDL2/SDL_render.h"

Renderable::Renderable() : _texturePtr(nullptr), _transformPtr(nullptr)
{
    _rect.x = 0;
    _rect.y = 0;
    _rect.w = 80;
    _rect.h = 80;

    _imageSize.x = 80;
    _imageSize.y = 80;


}

Renderable::Renderable(int posX, int posY, SDL_Texture& text, Vector2D imgSize)
{
    _rect.x = posX;
    _rect.y = posY;
    _rect.w = imgSize.x;

    _rect.h = imgSize.y;

    _imageSize = imgSize;

    setTexture(text);
}

Renderable::Renderable(const Renderable& r)
{
    _rect = r._rect;
    _texturePtr = r._texturePtr;
    _transformPtr = r._transformPtr;
    _imageSize = r._imageSize;
    _indexZ = r._indexZ;

    setTexture(*_texturePtr);
}

Renderable::~Renderable()
{
	Game::Instance().getRenderController().remove(*this);
}

void Renderable::init(SDL_Texture& text, Transform& tr, Vector2D imageSize)
{
    _texturePtr = &text;
    _transformPtr = &tr;
    _rect.x = tr.position.x;
    _rect.y = tr.position.y;
    _rect.w = imageSize.x;
    _rect.h = imageSize.y;

    _imageSize = imageSize;
    _indexZ = 0;

    setTexture(*_texturePtr);
}

void Renderable::init(SDL_Texture& text, Vector2D position, Vector2D imageSize)
{
    _texturePtr = &text;
    _rect.x = position.x;
    _rect.y = position.y;
    _rect.w = imageSize.x;
    _rect.h = imageSize.y;

    _imageSize = imageSize;
    _indexZ = 0;

    setTexture(*_texturePtr);
}

void Renderable::draw(SDL_Renderer& render)
{
    if (_texturePtr == nullptr)
    {
        SDL_LogDebug(2, "texture is null in draw");
        return;
    }

    if (_transformPtr)
    {
        _rect.x = _transformPtr->position.x; // - _imageSize.x;
        _rect.y = _transformPtr->position.y; // - _imageSize.y;

        // _rect.w = _imageSize.x * _transformPtr->scale.x;
        // _rect.h = _imageSize.y * _transformPtr->scale.y;
    }
    else
    {
        /*
        _rect.x = 0;
        _rect.y = 0;

        _rect.w = _imageSize.x;
        _rect.h = _imageSize.y;
        */
    }
    // SDL_Log("imageSize %d %d  texturePtr %d", _rect.w, _rect.h, _texturePtr);
    SDL_RenderCopy(&render, _texturePtr, NULL, &_rect);
}

void Renderable::setTexture(SDL_Texture& texture)
{
    // SDL_Log(" setTexture %p", this);
    _texturePtr = &texture;
	Game::Instance().getRenderController().add(this);
}

void Renderable::setTransform(Transform &transform)
{
    _transformPtr = &transform;
}

SDL_Rect Renderable::getRect()
{
    return _rect;
}
