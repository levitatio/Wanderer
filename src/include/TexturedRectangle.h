#ifndef TEXTUREDRECTANGLE_H
#define TEXTUREDRECTANGLE_H

#include <string>

#include "Vector2D.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class TexturedRectangle
{
	public: 
		TexturedRectangle();
		TexturedRectangle(const TexturedRectangle&);
		~TexturedRectangle();
		
		void init(const std::string& filePath, Vector2D size);
		// void render(SDL_Renderer& render, int x, int y, int scaleW = 1, int scaleH = 1);
		void render(SDL_Renderer& render, Vector2D pos, Vector2D scale);
		SDL_Texture* getTexture() { return _textPtr; }
		const std::string& getPath() { return _imagePath; }
			
	private:
		SDL_Rect _rect;
		SDL_Texture* _textPtr = nullptr;
		std::string _imagePath = "";
		Vector2D _initialSize;
};

#endif // TEXTUREDRECTANGLE_H
