#include "../include/eng_player.hpp"

#include <SDL2/SDL_rect.h>
#include <iostream>
#include <vector>

namespace eng {

EngPlayer::EngPlayer(Vector2f p_pos, SDL_Texture *p_tex, Vector2I p_spriteSize, EngWindow *engWindow)
    : EngEntity{p_pos, p_tex, p_spriteSize}, vel(0.0f, 0.0f) {}
void EngPlayer::move(Vector2f &direction) {

  if (abs(direction.x) == abs(direction.y)){
    vel.x += direction.x * sqrt(abs(direction.x));
    vel.y += direction.y * sqrt(abs(direction.y));
  } else {
    vel.x += direction.x;
    vel.y += direction.y;
  }

  if (direction.x == -1) sprite.y = 3;
  if (direction.x == 1) sprite.y = 1;
  if (direction.y == -1) sprite.y = 0;
  if (direction.y == 1) sprite.y = 2;

  if (direction.x != 0 || direction.y != 0){
    if (sprite.x == 0) sprite.x = 1;
    if(nextFrame >= 15){
      sprite.x += 1;
      if (sprite.x >= 3){
        sprite.x = 1;
      }
    nextFrame = 0;
    }
    nextFrame += 1;
  }else {
    sprite.x = 0;
  }

  this->setCurrentFrame(&sprite);

  return;
}
void EngPlayer::update() {

  Vector2f newPos;
  newPos.x = pos.x + (vel.x * constants::accel);
  newPos.y = pos.y + (vel.y * constants::accel);


  //TODO add new collision for other bodies, maybe somewhere else? bodies.hpp?

  /*
  // OLD COLLISION CODE FOR WALLS

  if (newPos.x <= 0) {
    vel.x = -vel.x * constants::friction;
    newPos.x = 0;
  } else if (newPos.x >=
             resolution.x / constants::scale - spriteSize.x) {
    vel.x = -vel.x * constants::friction;
    newPos.x = resolution.x / constants::scale - spriteSize.x;
  }


  if (newPos.y <= 0) {
    vel.y = -vel.y * constants::friction;
    newPos.y = 0;
  } else if (newPos.y >= resolution.y / constants::scale - spriteSize.y) {
    vel.y = -vel.y * constants::friction;
    newPos.y = resolution.y / constants::scale - spriteSize.y;
  }
  */

  pos.x = newPos.x;
  pos.y = newPos.y;

  return;
}


} // namespace eng