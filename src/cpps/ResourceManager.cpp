 #include "../include/RenderController.h"

ResourceManager::ResourceManager(SDL_Renderer& r)
{
	_rendererPtr = &r;
}

void ResourceManager::Init(SDL_Renderer& renderer) {
    _rendererPtr = &renderer;
}

void ResourceManager::add(Renderable* renderable) {
    // SDL_Log("renderable added : %p", renderable);
    _renderablesPtr.push_back(renderable);
}

void ResourceManager::remove(Renderable& renderable) {

    for (int i = _renderablesPtr.size() - 1; i > -1; i--)
    {
        if (_renderablesPtr[i] == &renderable)
        {
            _renderablesPtr.erase(_renderablesPtr.begin() + i);
        }
    }

}

void ResourceManager::render() {
	
	//Clear screen
    SDL_SetRenderDrawColor(_rendererPtr, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_rendererPtr);


    for (int i = 0; i < _renderablesPtr.size(); i++)
    {
        if (_renderablesPtr[i] != nullptr)
        {
            _renderablesPtr[i]->draw(*_rendererPtr);
        }
    }

	// update screen	
	SDL_RenderPresent(_rendererPtr);
}
