#include "../include/ResourceManager.h"
#include <SDL2/SDL_log.h>
#include <iostream>
#include <system_error>

ResourceManager::ResourceManager(SDL_Renderer &r) { _rendererPtr = &r; }

void ResourceManager::Init(SDL_Renderer &renderer) { _rendererPtr = &renderer; }

void ResourceManager::add(Renderable *renderable) {
  // SDL_Log("renderable added : %p", renderable);
  if (!renderable) {
    SDL_Log("Try to add nullptr");
  }
  _renderablesPtr.push_back(renderable);

  if (!_renderablesPtr.at(_renderablesPtr.size() - 1))
  {
    SDL_Log("Pushed a nullptr");
  }
}

void ResourceManager::remove(Renderable &renderable) {

  for (int i = _renderablesPtr.size() - 1; i > -1; i--) {
    if (_renderablesPtr[i] == &renderable) {
      _renderablesPtr.erase(_renderablesPtr.begin() + i);
    }
  }
}

void ResourceManager::render() {

  // Clear screen
  SDL_SetRenderDrawColor(_rendererPtr, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(_rendererPtr);

  if (!_rendererPtr) {
    SDL_Log("no renderer");
  }

  if (_renderablesPtr.size() < 1) {
    SDL_Log("no renderable in the array");
  }
  SDL_Log("amount of renderable %d", _renderablesPtr.size());
  
  int counter = 0;
  
    for (int i = 0; i < _renderablesPtr.size(); i++) {
      if (_renderablesPtr[i] != nullptr) {

        _renderablesPtr[i]->render(*_rendererPtr);
      }
      else {
      {
        counter++;
      }
      
    }

    }
      SDL_Log("%d renderable is nullptr", counter);
 
  

  // update screen
  SDL_RenderPresent(_rendererPtr);
}

SDL_Texture *ResourceManager::getTexture(const std::string &filePath) {
  SDL_Texture *text = nullptr;

  for (int i = 0; i < _renderablesPtr.size(); i++) {
    if (_renderablesPtr[i]->getTexturedRect().getPath() == filePath) {
      text = _renderablesPtr[i]->getTexturedRect().getTexture();
      break;
    }
  }

  if (!text) {
    text = loadSurface(filePath);
  }
  // _renderablesPtr.find()
  return text;
}

SDL_Texture *ResourceManager::loadSurface(const std::string &filePath) {
  SDL_Surface *loadedSurface = IMG_Load(filePath.c_str());
  if (loadedSurface == nullptr) {
    // Handle unsuccessful image loading
    std::cout << "Image could not be loaded! SDL Error: " << SDL_GetError()
              << std::endl;
    std::cout<< filePath << "  not found" << std::endl;
    return nullptr;
  }

  // SDL_Renderer* object
  SDL_Texture *text = SDL_CreateTextureFromSurface(_rendererPtr, loadedSurface);
  SDL_FreeSurface(loadedSurface);

  return text;
}
