#ifndef WANDERER_RESOURCEMANAGER_H
#define WANDERER_RESOURCEMANAGER_H

#include <vector>
#include "Renderable.h"

class ResourceManager {
    public:
	
	ResourceManager(SDL_Renderer&);

    SDL_Texture* getTexture(const std::string& filePath);
    SDL_Texture* loadSurface (const std::string& filePath);

    void Init(SDL_Renderer& renderer);
    void add(Renderable*);
    void remove(Renderable&);
    void render();

    private:
    SDL_Renderer* _rendererPtr;
    std::vector<Renderable*> _renderablesPtr;
};


#endif // WANDERER_RESOURCEMANAGER_H
