#include <SDL2/SDL.h>

#include "../include/eng_input.hpp"

#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
#include <iostream>

namespace eng {

void EngInput::inputCheck() {

  direction = {0,0};
  if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
    direction = {direction.x, direction.y - 1};
  }
  if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
    direction = {direction.x, direction.y + 1};
  }
  if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
    direction = {direction.x - 1, direction.y};
  }
  if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
    direction = {direction.x + 1, direction.y};
  }
  if (state[SDL_SCANCODE_SPACE]){
    direction.x = 2;
    direction.y = 2;
  }
  if (state[SDL_SCANCODE_E]){
    
  }
  return;
}
char EngInput::interactCheck(){

  if (state[SDL_SCANCODE_E]){
    return 'E';
  }

  return ' ';
}

} // namespace eng