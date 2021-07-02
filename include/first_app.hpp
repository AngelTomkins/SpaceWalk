#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "eng_window.hpp"
#include "eng_input.hpp"
#include "eng_entity.hpp"
#include "eng_player.hpp"
#include "eng_spaceship.hpp"
#include "utils.hpp"
#include "constants.hpp"
#include "eng_physics.hpp"

// std
#include <iostream>
#include <string>
#include <vector>

namespace eng {
class FirstApp {
public:
  FirstApp();
  ~FirstApp();
  void run();

private:

  EngInput engInput;
  EngWindow engWindow;
  PhysicsWorld physicsWorld;
  

};

} // namespace eng