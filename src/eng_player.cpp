#include "eng_player.hpp"

#include <iostream>

namespace eng {

EngPlayer::EngPlayer(Vector2f p_pos, SDL_Texture *p_tex)
    : EngEntity{p_pos, p_tex}, vel(0.0f, 0.0f) {}

void EngPlayer::move(Vector2f &direction) {
  vel.x += direction.x;
  vel.y += direction.y;

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
  return;
}
} // namespace eng