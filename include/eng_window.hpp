#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "eng_entity.hpp"
#include "constants.hpp"

// std
#include <string>

namespace eng {
class EngWindow {
public:
  void init();
  SDL_Texture* loadTexture(const char* filePath);

  int getRefershRate();

  void closeWindow();
  void clear();
  void render(EngEntity& p_entity,EngEntity& p_player );
  void display();


private:
  void initWindow();
  void initRenderer();

  SDL_Rect camera;

  int WIDTH;
  int HEIGHT;

  std::string windowName;

  SDL_Window *window;
  SDL_Renderer* renderer;
};
} // namespace eng