#include <SDL2/SDL.h>

#include "eng_input.hpp"

#include <SDL2/SDL_keycode.h>
#include <iostream>

namespace eng {

char EngInput::inputCheck(SDL_Event event) {
  char pressed;

  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
    case SDLK_UP:
    case SDLK_w:
      direction = {direction.x, -1};
      pressed = 'W';
      break;
    case SDLK_DOWN:
    case SDLK_s:
      direction = {direction.x, 1};
      pressed = 'S';
      break;
    case SDLK_LEFT:
    case SDLK_a:
      direction = {-1, direction.y};
      pressed = 'A';
      break;
    case SDLK_RIGHT:
    case SDLK_d:
      direction = {1, direction.y};
      pressed = 'D';
      break;
    default:
      direction = {0, 0};
      pressed = '-';
      break;
    }

    if (event.type == SDL_KEYUP) {
      switch (event.key.keysym.sym) {
      case SDLK_UP:
      case SDLK_w:
        direction = {direction.x, 0};
        pressed = 'W';
        break;
      case SDLK_DOWN:
      case SDLK_s:
        direction = {direction.x, 0};
        pressed = 'S';
        break;
      case SDLK_LEFT:
      case SDLK_a:
        direction = {0, direction.y};
        pressed = 'A';
        break;
      case SDLK_RIGHT:
      case SDLK_d:
        direction = {0, direction.y};
        pressed = 'D';
        break;
      default:
        direction = {0, 0};
        pressed = '-';
        break;
      }
    }
  }

    return pressed;
  }
} // namespace eng