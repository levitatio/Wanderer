#include "../include/Game.h"
#include <iostream>

void Game::test()
{
	SDL_Log("hello");
}

bool Game::init()
{
	// should init sdl
    //Start up SDL and create window
    if (!init_SDL()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return false;
    }

	if (!_rController)
	{
		_rController = new RenderController(*_renderer);
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
    _window = SDL_CreateWindow("Draw Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
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

    if (!loadImagesToTextures()){
        return false;
    }
    return true;
}


void Game::close() {


    destroyTextures();
    //Destroy window
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    _window = nullptr;
    _renderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}


void Game::destroyTextures() {
    for (int i = 0; i < 8; ++i) {
        SDL_DestroyTexture(_textureArr[i]);
    }
}


bool Game::loadImagesToTextures()
{

    //Init SDL_Image Library
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        //Handle unsuccessful SDL_Image initialization
        std::cout << "SDL_image library could not be initialized! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    std::string path = "/home/levi/src/learning_projects/sdl/Wanderer/resources/img/";
    //Load image at specified path. The path works the same as with txt files. It can be absolute or relative to the .exe file

    //The surfaces from images
    if (!loadSurface((path + "floor.png"), IMAGES::FLOOR)){
        std::cout << " floor.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    } else if (!loadSurface((path + "wall.png"), IMAGES::WALL)){
        std::cout << " wall.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    } else if (!loadSurface((path + "boss.png"), IMAGES::BOSS)){
        std::cout << " boss.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    } else if (!loadSurface((path + "skeleton.png"), IMAGES::SKELETON)){
        std::cout << " skeleton.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    } else if (!loadSurface((path + "hero-down.png"), IMAGES::HERODOWN)){
        std::cout << " hero-down.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    } else if (!loadSurface((path + "hero-up.png"), IMAGES::HEROUP)){
        std::cout << " hero-up.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    } else if (!loadSurface((path + "hero-left.png"), IMAGES::HEROLEFT)){
        std::cout << " hero-left.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    } else if (!loadSurface((path + "hero-right.png"), IMAGES::HERORIGHT)){
        std::cout << " hero-right.png image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}


bool Game::loadSurface (const std::string &fileName, IMAGES images)
{
    SDL_Surface* loadedSurface = IMG_Load( fileName.c_str() );
    if( loadedSurface == nullptr )
    {
        //Handle unsuccessful image loading
        std::cout << "Image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    //SDL_Renderer* object
    _textureArr[int(images)] = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return true;
}

