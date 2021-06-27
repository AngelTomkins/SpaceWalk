#include "eng_game_loop.hpp"
#include "eng_input.hpp"
#include "first_app.hpp"

namespace eng {
void EngGameLoop::mainLoop() {



  bool gameRunning = true;
  char pressed = ' ';

  while (gameRunning) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {

      case SDL_KEYDOWN:
        pressed = EngInput::inputCheck(event);
        break;

      case SDL_QUIT:
        gameRunning = false;
        break;
      }
    }
    

  }
}
} // namespace eng