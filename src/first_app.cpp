#include "first_app.hpp"

namespace eng {

FirstApp::FirstApp() {}

FirstApp::~FirstApp() {
    engWindow.closeWindow();
    SDL_Quit();
}

void FirstApp::run() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    std::cout << "Error Initiating SDL: " << SDL_GetError() << std::endl;
  
  if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "Error Initiating IMGs" << SDL_GetError() << std::endl;

    EngGameLoop::mainLoop();

    return;
}
} // namespace eng