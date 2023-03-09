#include "../include/TexturedRectangle.h"
#include "../include/Game.h"
#include <SDL2/SDL_rect.h>

TexturedRectangle::TexturedRectangle() 
{
	_imagePath = "";

	_rect.x = 0;
	_rect.y = 0;
	_rect.w = 0;
	_rect.h = 0;
}

TexturedRectangle::TexturedRectangle(const TexturedRectangle& t)
{
	_textPtr = t._textPtr;
	_imagePath = t._imagePath;
	_initialSize = t._initialSize;
	_rect = t._rect;
}

void TexturedRectangle::init(const std::string& filePath, Vector2D size)
{
	_initialSize = size;
	_imagePath = filePath;
	_textPtr = Game::Instance().getResourceManager().getTexture(filePath);
}

TexturedRectangle::~TexturedRectangle()
{
	SDL_DestroyTexture(_textPtr);
	_textPtr = nullptr;
}

void TexturedRectangle::render(SDL_Renderer& render, Vector2D pos, Vector2D scale)
{
	_rect.x = pos.x;
	_rect.y = pos.y;
	SDL_Log("initialsize.x: %f initialsize.y: %f scale.x: %f scale.y: %f", _initialSize.x, _initialSize.y, scale.x, scale.y);
	_rect.w = (int)(_initialSize.x * scale.x);
	_rect.h = (int)(_initialSize.y * scale.y);
	
	SDL_Log("render to rect x: %d y: %d w: %d h: %d", _rect.x, _rect.y, _rect.w, _rect.h);
	SDL_RenderCopy(&render, _textPtr, NULL, &_rect);
}
