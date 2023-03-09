#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "ResourceManager.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

class Game : public Singleton<Game>
{
	public:
		bool init();
		void close();
		void test();

		ResourceManager& getResourceManager() { return *_resourceManager; };
	// here should be global accessible objects
		int TILE_UNIT = 80;
		int SCREEN_HEIGHT = 800;
		int SCREEN_WIDTH = 800;
	private:
		bool init_SDL();
		
		ResourceManager* _resourceManager = nullptr;
		SDL_Window* _window = nullptr;
		SDL_Renderer* _renderer = nullptr;
};	     


#endif // GAME_H

