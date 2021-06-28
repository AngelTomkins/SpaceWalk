#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

#include "eng_math.hpp"

namespace eng {
class EngEntity {
public:
  EngEntity(Vector2f p_pos, SDL_Texture* p_tex);

  Vector2f& getPos(){ return pos; }

  SDL_Texture* getTex() { return tex; }
  void setTex(SDL_Texture* p_tex) { tex = p_tex; return; }
  SDL_Rect getCurrentFrame() {return currentFrame; }

protected:
  Vector2f pos;
  float mass;
  SDL_Rect currentFrame;
  SDL_Texture* tex;
};

} // namespace eng
