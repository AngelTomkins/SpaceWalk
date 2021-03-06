#include "../include/eng_window.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include <SDL2/SDL_video.h>
#include <iostream>

namespace eng {

void EngWindow::init() {
  WIDTH = resolution.x;
  HEIGHT = resolution.y;
  halfWIDTH = WIDTH/2;
  halfHEIGHT = HEIGHT/2;

  windowName = constants::windowName;

  initWindow();
  initRenderer();
}

void EngWindow::initWindow() {
  window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                            SDL_WINDOW_SHOWN);
  camera = {0, 0, 1000, 1000};
}

void EngWindow::closeWindow() { SDL_DestroyWindow(window); }

void EngWindow::initRenderer() {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *EngWindow::loadTexture(const char *filePath) {
  SDL_Texture *texture = nullptr;
  texture = IMG_LoadTexture(renderer, filePath);

  if (texture == NULL)
    std::cout << "Failed to load texture. Error: " << SDL_GetError()
              << std::endl;

  return texture;
}

int EngWindow::getRefershRate() {
  int displayIndex = SDL_GetWindowDisplayIndex(window);

  SDL_DisplayMode mode;

  SDL_GetDisplayMode(displayIndex, 0, &mode);
  return mode.refresh_rate;
}

void EngWindow::clear() { SDL_RenderClear(renderer); }

void EngWindow::render(EngEntity &p_entity, EngEntity &p_player) {
  
  camera.x = p_player.getPos().x * constants::scale - halfWIDTH + p_player.getSpriteSize().x;
  camera.y = p_player.getPos().y * constants::scale - halfHEIGHT + p_player.getSpriteSize().y;
  
  SDL_Rect src;

  src.x = p_entity.getCurrentFrame().x *  p_entity.getSpriteSize().x;
  src.y = p_entity.getCurrentFrame().y *  p_entity.getSpriteSize().y;
  src.w = p_entity.getSpriteSize().x;
  src.h = p_entity.getSpriteSize().y;

  SDL_Rect dst;
  dst.x = p_entity.getPos().x * constants::scale - camera.x;
  dst.y = p_entity.getPos().y * constants::scale - camera.y;
  dst.w = src.w * constants::scale;
  dst.h = src.h * constants::scale;

  SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void EngWindow::display() { SDL_RenderPresent(renderer); }
} // namespace eng