#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "eng_game_loop.hpp"
#include "eng_window.hpp"

// std
#include <iostream>
#include <string>

namespace eng {
class FirstApp {
public:
  FirstApp();
  ~FirstApp();
  void run();

private:
  int HEIGHT = 800;
  int WIDTH = 600;
  std::string NAME = "SDL Window";

  EngWindow engWindow{WIDTH, HEIGHT, NAME};

};

} // namespace eng