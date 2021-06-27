#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// std
#include <string>

namespace eng {
class EngWindow {
public:
  EngWindow(int w, int h, std::string name);
  SDL_Texture* loadTexture(const char* filePath);

  void closeWindow();
  void clear();
  void render(SDL_Texture* tex);
  void display();

private:
  void initWindow();
  void initRenderer();

  int WIDTH;
  int HEIGHT;

  std::string windowName;

  SDL_Window *window;
  SDL_Renderer* renderer;
};
} // namespace eng