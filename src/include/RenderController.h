#ifndef WANDERER_RENDERCONTROLLER_H
#define WANDERER_RENDERCONTROLLER_H

#include <vector>
#include "Renderable.h"

class Renderable;

class RenderController {
    public:
    static RenderController& Instance()
    {
        if (!_pInstance)
        {
            Create();
        }

        return *_pInstance;
    }

    void Init(SDL_Renderer& renderer);
    void add(Renderable*);
    void remove(Renderable&);
    void render();

    private:
    RenderController() {};
    RenderController(const RenderController&) {};
    ~RenderController()
    {
        _pInstance = nullptr;
    };

    std::vector<Renderable*> _renderablePtr;
    SDL_Renderer* _rendererPtr;

    static RenderController* _pInstance;
    static void Create() { _pInstance = new RenderController(); };
};


#endif // WANDERER_RENDERCONTROLLER_H
