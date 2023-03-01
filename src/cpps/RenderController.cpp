 #include "../include/RenderController.h"

RenderController* RenderController::_pInstance = nullptr;

void RenderController::Init(SDL_Renderer& renderer) {
    _rendererPtr = &renderer;
}

void RenderController::add(Renderable* renderable) {
    // SDL_Log("renderable added : %p", renderable);
    _renderablePtr.push_back(renderable);
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
