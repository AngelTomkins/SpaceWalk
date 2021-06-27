#include "first_app.hpp"

namespace eng {


FirstApp::~FirstApp() {
  engWindow.closeWindow();
  SDL_Quit();
}

void FirstApp::run() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    std::cout << "Error Initiating SDL: " << SDL_GetError() << std::endl;

  if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "Error Initiating IMGs" << SDL_GetError() << std::endl;
    

  SDL_Texture* backgroundTexture = engWindow.loadTexture("gfx/bg.png");

  bool gameRunning = true;
  char pressed = ' ';

  while (gameRunning) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {

      case SDL_QUIT:
        gameRunning = false;
        break;
        
      case SDL_KEYDOWN:
        pressed = engInput.inputCheck(event);
        break;
        
      }
    }
    engWindow.clear();
    engWindow.render(backgroundTexture);
    engWindow.display();


  }

  

  return;
}
} // namespace eng