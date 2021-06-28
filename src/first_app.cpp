#include "first_app.hpp"

#include <iostream>

namespace eng {


FirstApp::FirstApp(){
}
  
FirstApp::~FirstApp() {
  engWindow.closeWindow();
  SDL_Quit();
}

void FirstApp::run() {
  engWindow.init(constants::startWidth, constants::startHeight, constants::windowName);
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    std::cout << "Error Initiating SDL: " << SDL_GetError() << std::endl;

  if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "Error Initiating IMGs" << SDL_GetError() << std::endl;

  SDL_Texture *playerTex = engWindow.loadTexture("gfx/bg.png");

  EngPlayer player = {Vector2f(0,0), playerTex};

  bool gameRunning = true;

  const float timeStep = 0.01f;
  float accumulator = 0.0f;
  float currentTime = utils::hireTimeInSeconds();

  char pressed = ' ';

  while (gameRunning) {
    SDL_Event event;

      int startTicks = SDL_GetTicks();

      float newTime = utils::hireTimeInSeconds();
      float frameTime = newTime - currentTime;

      currentTime = newTime;
      accumulator += frameTime;

    while (accumulator >= timeStep) 
    {

      while (SDL_PollEvent(&event)) 
      {
        switch (event.type) 
        {
        case SDL_QUIT:
          gameRunning = false;
          break;

        case SDL_KEYDOWN:
          pressed = engInput.inputCheck(event);
          player.move(engInput.getDirection());
          break;
        }
      }
      accumulator -= timeStep;
    }
    player.update();
    // const float alpha = accumulator / timeStep;

    engWindow.clear();
    // for (EngEntity &e : entities) {
    //   engWindow.render(e);
    // }
    engWindow.render(player);

    engWindow.display();

    int frameTicks = SDL_GetTicks() - startTicks;

    if (frameTicks < 1000 / engWindow.getRefershRate())
      SDL_Delay(1000 / engWindow.getRefershRate() - frameTicks);
  }

  return;
}
} // namespace eng