#pragma once

#include <SDL2/SDL.h>

// std
#include <string>

namespace eng {
class EngWindow {
public:
  EngWindow(int w, int h, std::string name);
  ~EngWindow();

  void closeWindow();
  SDL_Window *window;

private:
  void initWindow();

  int WIDTH;
  int HEIGHT;

  std::string windowName;
};
} // namespace eng