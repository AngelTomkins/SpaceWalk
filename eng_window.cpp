#include "eng_window.hpp"

namespace eng {

EngWindow::EngWindow(int w, int h, std::string name) : WIDTH{w}, HEIGHT{h}, windowName{name} {
    initWindow();
}
EngWindow::~EngWindow() {}

void EngWindow::initWindow() {
  window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, 0);
}

void EngWindow::closeWindow() {
    SDL_DestroyWindow(window);
}

} // namespace eng