#pragma once

#include "eng_body.hpp"
#include "eng_window.hpp"
#include "eng_math.hpp"


namespace eng{
class EngSpaceship{
  EngSpaceship(glm::vec2 p_pos, SDL_Texture* p_tex, Vector2I p_spriteSize, EngWindow* engWindow);

};
}