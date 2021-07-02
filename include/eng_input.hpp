#pragma once

#include <SDL2/SDL.h>


#include <glm/vec2.hpp>

namespace eng {
class EngInput {

public:
  void inputCheck();
  char interactCheck();
  glm::vec2& getDirection() { return direction; }


private:
  glm::vec2 direction;
  const Uint8 *state = SDL_GetKeyboardState(nullptr);
};
} // namespace eng