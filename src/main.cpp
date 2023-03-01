#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>

#include <SDL2/SDL.h>
// #include "Drawable.h"

#include "include/MapTile.h"
#include "include/Monster.h"
#include "include/Hero.h"
#include "include/Renderable.h"
#include "include/RenderController.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int TILE_UNIT = 80;

void draw(SDL_Renderer* gRenderer);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

bool loadImagesToTextures();
void destroyTextures();
bool loadSurface (const std::string&, IMAGES);
void drawHero(int);
void moveHero(SDL_KeyCode kCode);

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

//The texture
SDL_Texture* gTextures[8];  // stored texture pointers

RenderController* gRenderController  = nullptr;


bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Draw Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    if (!loadImagesToTextures()){
        return false;
    }
    return true;
}

void close() {


    destroyTextures();
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();RenderController(*gRenderer);
        return -1;
    }

    RenderController::Instance().Init(*gRenderer);

    //Main loop flag
    bool quit = false;
    srand (time(NULL));
    //Event handler
    SDL_Event e;


    MapTile mapTile(*gTextures[int(IMAGES::WALL)], *gTextures[int(IMAGES::FLOOR)]);
    mapTile.createMap();
    Hero hero(mapTile, *gTextures[int(IMAGES::HERODOWN)]);
    Monster monster(mapTile, 480, 240, *gTextures[int(IMAGES::SKELETON)]);
    Monster monster2(mapTile, 720, 720, *gTextures[int(IMAGES::SKELETON)]);


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

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        //draw(gRenderer);


        // mapTile.renderMap(gRenderer);

        RenderController::Instance().render();

        //SDL_Delay(100);
        //drawImages ();
        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}


bool loadImagesToTextures()
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

bool loadSurface (const std::string &fileName, IMAGES images)
{
    SDL_Surface* loadedSurface = IMG_Load( fileName.c_str() );
    if( loadedSurface == nullptr )
    {
        //Handle unsuccessful image loading
        std::cout << "Image could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    //SDL_Renderer* object
    gTextures[int(images)] = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return true;
}

void destroyTextures() {
    for (int i = 0; i < 8; ++i) {
        SDL_DestroyTexture(gTextures[i]);
    }

}
void drawHero (int numb){
    SDL_Rect rect = {2 * 80, 5 * 80, 80, 80};
    SDL_RenderCopy(gRenderer, gTextures[numb], NULL, &rect);
}
