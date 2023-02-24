#ifndef WANDERER_RENDERCONTROLLER_H
#define WANDERER_RENDERCONTROLLER_H

#include <vector>
#include "Renderable.h"

class Renderable;

class RenderController {
    public:
    RenderController(SDL_Renderer& renderer);
    ~RenderController();

    void add(Renderable&);
    void remove(Renderable&);
    void render();
    
    private:
    std::vector<Renderable*> _renderablePtr;
    SDL_Renderer* _rendererPtr;
};


#endif // WANDERER_RENDERCONTROLLER_H