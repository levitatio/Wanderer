#ifndef WANDERER_RENDERABLE_H
#define WANDERER_RENDERABLE_H

#include <SDL2/SDL.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <string>

#include "TexturedRectangle.h"
#include "Transform.h"


enum class IMAGES{
    FLOOR, WALL, BOSS, SKELETON, HERODOWN, HEROUP, HEROLEFT, HERORIGHT
};

class Renderable {
public:
    Renderable();
    Renderable(const std::string& filePath, int, int, Vector2D);
    Renderable(const Renderable&);
    ~Renderable();

	// std::string& getPath() { return _imagePath; }
	// SDL_Texture* getTexture() { return _texturePtr; } 
    TexturedRectangle& getTexturedRect() { return _texturedRect; }

    void init(const std::string& path, Transform& tr, Vector2D imageSize);
    void init(const std::string& path, Vector2D position, Vector2D imageSize);
    void render(SDL_Renderer& render);
    // void setTexture(SDL_Texture& texture);
    void setTransform(Transform& transform);
    // SDL_Rect getRect();
    Transform _transform;
protected:
    TexturedRectangle _texturedRect;
    // Transform* _transformPtr;
    int _indexZ = 0;
};

#endif //WANDERER_RENDERABLE_H
