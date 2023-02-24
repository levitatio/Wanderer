 #include "../include/RenderController.h"

 RenderController::RenderController(SDL_Renderer& renderer) {
    _rendererPtr = &renderer;
}

RenderController::~RenderController() {
    _renderablePtr.clear();
}

void RenderController::add(Renderable& renderable) {
    _renderablePtr.push_back(&renderable);
}

void RenderController::remove(Renderable& renderable) {
    
    for (int i = _renderablePtr.size() - 1; i > -1; i--)
    {
        if (_renderablePtr[i] == &renderable) 
        {
            _renderablePtr.erase(_renderablePtr.begin() + i);
        }
    }
    
}

void RenderController::render() {
    for (int i = 0; i < _renderablePtr.size(); i++)
    {
        if (_renderablePtr[i] != nullptr)
        {
            _renderablePtr[i]->draw(*_rendererPtr);
        }
    }
}
