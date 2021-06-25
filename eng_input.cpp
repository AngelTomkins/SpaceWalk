#include <SDL2/SDL.h>

//headers
#include "eng_input.hpp"

//std
#include <iostream>

namespace eng {

  char EngInput::inputCheck(SDL_Event event) {
    char pressed;

    switch (event.key.keysym.scancode) {
    case SDL_SCANCODE_W:
    case SDL_SCANCODE_UP:
      pressed = 'W';
      break;
    case SDL_SCANCODE_A:
    case SDL_SCANCODE_LEFT:
      pressed = 'A';
      break;
    case SDL_SCANCODE_S:
    case SDL_SCANCODE_DOWN:
      pressed = 'S';
      break;
    case SDL_SCANCODE_D:
    case SDL_SCANCODE_RIGHT:
      pressed = 'D';
      break;
    default:
      pressed = '-';
      break;
    }
    std::cout << pressed << std::endl;
    return pressed;
  }
} // namespace eng