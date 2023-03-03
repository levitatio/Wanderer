#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "Renderable.h"
#include "RenderController.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

class Game : public Singleton<Game>
{
	public:
		bool init();
		void close();
		void test();

		RenderController& getRenderController() { return *_rController; };
		SDL_Texture** getTextures() { return _textureArr; }
	// here should be global accessible objects
	private:
		bool init_SDL();
		void destroyTextures();
		bool loadSurface(const std::string&, IMAGES);
		bool loadImagesToTextures();

		RenderController* _rController = nullptr;
		SDL_Window* _window = nullptr;
		SDL_Renderer* _renderer = nullptr;
		SDL_Texture* _textureArr[8];
};	     


#endif // GAME_H

