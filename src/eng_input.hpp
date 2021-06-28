#pragma once

#include <SDL2/SDL.h>


#include "eng_math.hpp"

namespace eng {
class EngInput {

public:
  char inputCheck(SDL_Event event);
  Vector2f& getDirection() { return direction; }

private:
  Vector2f direction;
};
} // namespace eng