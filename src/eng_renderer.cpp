#include "eng_renderer.hpp"

namespace eng {

EngRenderer::EngRenderer(EngWindow &window) : window{window} {  
  SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
  SDL_FreeSurface(surface);
  SDL_Rect dest;
}
}