#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "eng_window.hpp"

namespace eng {
class EngRenderer {
public:
  EngRenderer(EngWindow &engWindow);
  ~EngRenderer();

private:
  EngWindow &window;
  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  SDL_Renderer* rend = SDL_CreateRenderer(window.window, -1, render_flags);
  SDL_Surface* surface;
  EngWindow engWindow();

};
} // namespace eng