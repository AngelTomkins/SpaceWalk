#include "eng_player.hpp"

#include <iostream>
#include <ostream>

namespace eng {

EngPlayer::EngPlayer(Vector2f p_pos, SDL_Texture *p_tex, EngWindow* engWindow)
    : EngEntity{p_pos, p_tex}, vel(0.0f, 0.0f) {

    dir = 0;

    textures[0] = engWindow->loadTexture("gfx/Player/Player_Up.png");
    // textures[1] = engWindow->loadTexture("gfx/Player/.png");
    textures[2] = engWindow->loadTexture("gfx/Player/Player_Down.png");
    // textures[3] = engWindow->loadTexture("gfx/Player/.png");
    textures[4] = engWindow->loadTexture("gfx/Player/Player_Right.png");
    // textures[5] = engWindow->loadTexture("gfx/Player/.png");
    textures[6] = engWindow->loadTexture("gfx/Player/Player_Left.png");
    // textures[7] = engWindow->loadTexture("gfx/Player/.png");

      
    }

void EngPlayer::move(Vector2f &direction) {
  vel.x += direction.x;
  vel.y += direction.y;

  // if (direction.x == -1){
  //   if (direction.y == -1){
  //     dir = 5;
  //   } else if (direction.y == 0){
  //     dir = 6;
  //   } else if (direction.y == 1){
  //     dir = 7;
  //   }
  // } else if (direction.x == 0){
  //   if (direction.y == -1){
  //     dir = 4;
  //   } else if (direction.y == 1){
  //     dir = 0;
  //   }
  // } else if (direction.x == 1){
  //   if (direction.y == -1){
  //     dir = 3;
  //   } else if (direction.y == 0){
  //     dir = 2;
  //   } else if (direction.y == 1){
  //     dir = 1;
  //   }
  // }
  

  return;
}
void EngPlayer::update() {

  Vector2f newPos;
  newPos.x = pos.x + (vel.x * constants::accel);
  newPos.y = pos.y + (vel.y * constants::accel);

  if (newPos.x <= 0){
    vel.x = -vel.x * constants::friction;
    newPos.x = 0;
  } else if (newPos.x >= constants::startWidth / constants::scale  - this->currentFrame.w){
    vel.x = -vel.x * constants::friction;
    newPos.x = constants::startWidth / constants::scale  - this->currentFrame.w;

  }

  if (newPos.y <= 0){
    vel.y = -vel.y * constants::friction;
    newPos.y = 0;
  } else if (newPos.y >= constants::startHeight / constants::scale - this->currentFrame.h){
    vel.y = -vel.y * constants::friction;
    newPos.y = constants::startHeight / constants::scale - this->currentFrame.h; 
  }

  pos.x = newPos.x;
  pos.y = newPos.y;


  // this->setTex(textures[dir]);
  

  return;
}
} // namespace eng