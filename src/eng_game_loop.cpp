#include "eng_game_loop.hpp"
#include "eng_input.hpp"

namespace eng {
void EngGameLoop::mainLoop() {

  int close = 0;
  char pressed = ' ';

  while (!close) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {

      case SDL_QUIT:
        close = 1;
        break;

      case SDL_KEYDOWN:
        pressed = EngInput::inputCheck(event);
        break;
      }
    }
  }
}
} // namespace eng