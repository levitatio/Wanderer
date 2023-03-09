#include "../include/Game.h"
#include <iostream>

bool Game::init()
{
	// should init sdl
    //Start up SDL and create window
    if (!init_SDL()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return false;
    }

	if (!_resourceManager)
	{
		_resourceManager = new ResourceManager(*_renderer);
	}

	return true;
}


bool Game::init_SDL() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    _window = SDL_CreateWindow("render Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (_window == nullptr) {

        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }


    //Create renderer for window
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    /*
    if (!loadImagesToTextures()){
        return false;
    }
    */
    return true;
}


void Game::close() {


    // destroyTextures();
    //Destroy window
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    _window = nullptr;
    _renderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}
