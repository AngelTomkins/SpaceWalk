#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

#include <glm/vec2.hpp>

#include "eng_math.hpp"

namespace eng {
class EngEntity {
public:
  EngEntity(glm::vec2 p_pos, SDL_Texture* p_tex, Vector2I spriteSize);

  glm::vec2& getPos(){ return pos; }
  void setPos(glm::vec2 p) { pos = p; }

  SDL_Texture* getTex() { return tex; }
  void setTex(SDL_Texture* p_tex) { tex = p_tex; return; }
  SDL_Rect getCurrentFrame() {return currentFrame; }
  void setCurrentFrame(Vector2I * xy);
  Vector2I getSprite() {return sprite; }
  Vector2I getSpriteSize() {return spriteSize; }

protected:

  Vector2I sprite {0,0};
  Vector2I spriteSize;
  glm::vec2 pos;
  SDL_Rect currentFrame;
  SDL_Texture* tex;
};
} // namespace eng
