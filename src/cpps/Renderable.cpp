#include "../include/Renderable.h"
#include "../include/Game.h"
#include "../include/TexturedRectangle.h"

Renderable::Renderable()  {}

Renderable::Renderable(const std::string &filePath, int posX, int posY,
                       Vector2D imgSize) {
  _indexZ = 0;
}

Renderable::Renderable(const Renderable &r) {

  _transform = r._transform;
  _indexZ = r._indexZ;
  _texturedRect = r._texturedRect;
  // ??
  // Game::Instance().getResourceManager().add(this);
}

Renderable::~Renderable() {
  // free texture if it was the last renderable
}

void Renderable::init(const std::string &filePath, Transform &tr,
                      Vector2D imageSize) {
  _transform = tr;
  _indexZ = 0;

  _texturedRect.init(filePath, imageSize);
  Game::Instance().getResourceManager().add(this);
}

void Renderable::init(const std::string &filePath, Vector2D position,
                      Vector2D imageSize) {
  _indexZ = 0;

  _transform.position = position;
  _transform.scale = Vector2D(1, 1);
  _transform.indexZ = 0;

  _texturedRect.init(filePath, imageSize);

  Game::Instance().getResourceManager().add(this);
}

void Renderable::render(SDL_Renderer &render) {
  // it should be has Texture or something like that

  if (_texturedRect.getTexture() == nullptr) {
    SDL_Log("no texture");
    return;
  }

  _texturedRect.render(render, _transform.position, _transform.scale);
}

void Renderable::setTransform(Transform &transform) { _transform = transform; }
