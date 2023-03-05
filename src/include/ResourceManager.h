#ifndef WANDERER_RENDERCONTROLLER_H
#define WANDERER_RENDERCONTROLLER_H

#include <vector>
#include "Renderable.h"

class Renderable;

class ResourceManager {
    public:
	
	ResourceManager(SDL_Renderer&);

    void Init(SDL_Renderer& renderer);
    void add(Renderable*);
    void remove(Renderable&);
    void render();

    private:
    SDL_Renderer* _rendererPtr;
    std::vector<Renderable*> _renderablesPtr;
};


#endif // WANDERER_RENDERCONTROLLER_H
