#include "../include/first_app.hpp"

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
  SDL_Texture *spaceshipTex = engWindow.loadTexture("gfx/SpaceShip/Spaceship.png");

  EngEntity background = {glm::vec2(0,0), bgTex, Vector2I(1000,1000)};
  EngPlayer player = {glm::vec2(0,0), playerTex, Vector2I(32,32), 200, &engWindow};
  dynamicBody spaceship = {glm::vec2{32,32}, spaceshipTex, Vector2I{192,96}, 20000};

  physicsWorld.addBody(&player);
  physicsWorld.addBody(&spaceship);


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
      
      engInput.inputCheck();
      player.move(engInput.getDirection());
      player.interact(engInput.interactCheck());

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
    physicsWorld.step();
    // spaceship.updateVelocity(&bodies);

    engWindow.clear();
    engWindow.render(background, player);
    engWindow.render(spaceship, player);
    engWindow.render(player, player);

    engWindow.display();

    int frameTicks = SDL_GetTicks() - startTicks;

    if (frameTicks < 1000 / engWindow.getRefershRate())
      SDL_Delay(1000 / engWindow.getRefershRate() - frameTicks);

  }

  return;
}
} // namespace eng