#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>

#include <SDL2/SDL.h>
// #include "renderable.h"

#include "include/Game.h"
#include "include/MapTile.h"
#include "include/Monster.h"
#include "include/Hero.h"
#include "include/Renderable.h"
#include "include/ResourceManager.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int TILE_UNIT = 80;


int main(int argc, char *args[]) {
    
	Game::Instance().init();

    //Main loop flag
    bool quit = false;
    srand (time(NULL));
    //Event handler
    SDL_Event e;

    std::string imgFolderPath = "/home/levi/src/learning_projects/sdl/Wanderer/resources/img";

    MapTile mapTile("/home/levi/src/learning_projects/sdl/Wanderer/resources/img/wall.png", "/home/levi/src/learning_projects/sdl/Wanderer/resources/img/floor.png");
    mapTile.createMap();
    Hero hero(mapTile, "/home/levi/src/learning_projects/sdl/Wanderer/resources/img/hero-down.png");
    Monster monster(mapTile, 480, 240, "/home/levi/src/learning_projects/sdl/Wanderer/resources/img/skeleton.png");
    Monster monster2(mapTile, 720, 720, "/home/levi/src/learning_projects/sdl/Wanderer/resources/img/skeleton.png");


    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }else if( e.type == SDL_KEYDOWN ) {
                // SDL_Log("in loop");
                switch( e.key.keysym.sym ) {
                    case SDLK_UP:
                        //Pressed Up
                        hero.moving(DIRECTION::UP);
                        break;
                    case SDLK_DOWN:
                        //Pressed Down
                        hero.moving(DIRECTION::DOWN);
                        break;
                    case SDLK_LEFT:
                        //Pressed Left
                        hero.moving(DIRECTION::LEFT);
                        break;
                    case SDLK_RIGHT:
                        //Pressed Right
                        hero.moving(DIRECTION::RIGHT);
                        break;
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        //Pressed something else
                        break;
                }

                // SDL_Log("after hero Move");
                monster.moving();
                monster2.moving();
                // SDL_Log("after monsters Move");
            }
        }

        // SDL_Log("will render");
		Game::Instance().getResourceManager().render();
        // SDL_Log("has rendered");

        SDL_Delay(100);
		
    }

    //Free resources and close SDL
	Game::Instance().close();

    return 0;
}

