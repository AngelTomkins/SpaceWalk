#include "first_app.hpp"

#include <SDL2/SDL_video.h>
#include <iostream>

namespace eng {


FirstApp::FirstApp(){
}
  
FirstApp::~FirstApp() {
  engWindow.closeWindow();
  SDL_Quit();
}

void FirstApp::run() {
  engWindow.init();
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    std::cout << "Error Initiating SDL: " << SDL_GetError() << std::endl;

  if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "Error Initiating IMGs" << SDL_GetError() << std::endl;

  SDL_Texture *playerTex = engWindow.loadTexture("gfx/Player/Player_Sheet.png");
  SDL_Texture *bgTex = engWindow.loadTexture("gfx/bg.png");

  EngEntity background = {Vector2f(0,0), bgTex, Vector2I(1000,1000)};
  EngPlayer player = {Vector2f(0,0), playerTex, Vector2I(32,32), &engWindow};

  bool gameRunning = true;

  const float timeStep = 0.01f;
  float accumulator = 0.0f;
  float currentTime = utils::hireTimeInSeconds();


  while (gameRunning) {
    SDL_Event event;

      int startTicks = SDL_GetTicks();

      float newTime = utils::hireTimeInSeconds();
      float frameTime = newTime - currentTime;

      currentTime = newTime;
      accumulator += frameTime;
      
      engInput.inputCheck(event);
      player.move(engInput.getDirection());

    while (accumulator >= timeStep) 
    {

      while (SDL_PollEvent(&event)) 
      {
        if(event.type == SDL_QUIT)
          gameRunning = false;

      }
      accumulator -= timeStep;
    }
    player.update();

    engWindow.clear();
    engWindow.render(background);
    engWindow.render(player);

    engWindow.display();

    int frameTicks = SDL_GetTicks() - startTicks;

    if (frameTicks < 1000 / engWindow.getRefershRate())
      SDL_Delay(1000 / engWindow.getRefershRate() - frameTicks);

  }

  return;
}
} // namespace eng