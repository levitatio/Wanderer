 #include "../include/RenderController.h"


void RenderController::Init(SDL_Renderer& renderer) {
    _rendererPtr = &renderer;
}

void RenderController::add(Renderable* renderable) {
    // SDL_Log("renderable added : %p", renderable);
    _renderablesPtr.push_back(renderable);
}

void RenderController::remove(Renderable& renderable) {

    for (int i = _renderablesPtr.size() - 1; i > -1; i--)
    {
        if (_renderablesPtr[i] == &renderable)
        {
            _renderablesPtr.erase(_renderablesPtr.begin() + i);
        }
    }

}

void RenderController::render() {

    for (int i = 0; i < _renderablesPtr.size(); i++)
    {
        if (_renderablesPtr[i] != nullptr)
        {
            _renderablesPtr[i]->draw(*_rendererPtr);
        }
    }
}
