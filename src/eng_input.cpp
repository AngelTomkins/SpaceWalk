#include <SDL2/SDL.h>

#include "eng_input.hpp"

#include <iostream>

namespace eng {

  char EngInput::inputCheck(SDL_Event event) {
    char pressed;

    direction = {0,0};

    switch (event.key.keysym.scancode) {
    case SDL_SCANCODE_W:
    case SDL_SCANCODE_UP:
      direction = {direction.x, direction.y - 1};
      pressed = 'W';
      break;
    case SDL_SCANCODE_S:
    case SDL_SCANCODE_DOWN:
      direction = {direction.x, direction.y + 1};
      pressed = 'S';
      break;
    case SDL_SCANCODE_A:
    case SDL_SCANCODE_LEFT:
      direction = {direction.x - 1, direction.y};
      pressed = 'A';
      break;
    case SDL_SCANCODE_D:
    case SDL_SCANCODE_RIGHT:
      direction = {direction.x + 1, direction.y};
      pressed = 'D';
      break;
    default:
      direction = {0,0};
      pressed = '-';
      break;
    }
    return pressed;
  }
} // namespace eng