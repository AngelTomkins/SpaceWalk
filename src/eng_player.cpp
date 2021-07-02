#include "../include/eng_player.hpp"

#include <SDL2/SDL_rect.h>
#include <iostream>
#include <vector>

namespace eng {

EngPlayer::EngPlayer(glm::vec2 p_pos, SDL_Texture *p_tex, Vector2I p_spriteSize,
                     float mass, EngWindow *engWindow)
    : dynamicBody{p_pos, p_tex, p_spriteSize, mass}{}
void EngPlayer::move(glm::vec2 &direction) {

  // if space is pressed, slow down player to a stop
  if (direction.x == 2 || direction.y == 2) {
    if (velocity.x > 0) {
      direction.x = -1;
    } else if (velocity.x < 0) {
      direction.x = 1;
    } else {
      direction.x = 0;
    }
    if (velocity.y > 0) {
      direction.y = -1;
    } else if (velocity.y < 0) {
      direction.y = 1;
    } else {
      direction.y = 0;
    }
  }

  if (abs(direction.x) == abs(direction.y)) {
    force.x = direction.x * sqrt(abs(direction.x)) * constants::accel;
    force.y = direction.y * sqrt(abs(direction.y)) * constants::accel;
  } else {
    force.x = direction.x * constants::accel;
    force.y = direction.y * constants::accel;
  }

  if (direction.x == -1)
    sprite.y = 3;
  if (direction.x == 1)
    sprite.y = 1;
  if (direction.y == -1)
    sprite.y = 0;
  if (direction.y == 1)
    sprite.y = 2;

  if (direction.x != 0 || direction.y != 0) {
    if (sprite.x == 0)
      sprite.x = 1;
    if (nextFrame >= 15) {
      sprite.x += 1;
      if (sprite.x >= 3) {
        sprite.x = 1;
      }
      nextFrame = 0;
    }
    nextFrame += 1;
  } else {
    sprite.x = 0;
  }

  this->setCurrentFrame(&sprite);

  return;
}
void EngPlayer::update() {



  /*
  glm::vec2 newPos;
  newPos.x = pos.x + (velocity.x * constants::accel);
  newPos.y = pos.y + (velocity.y * constants::accel);

  // TODO add new collision for other bodies, maybe somewhere else? bodies.hpp?

  
  // OLD COLLISION CODE FOR WALLS

  if (newPos.x <= 0) {
    velocity.x = -velocity.x * constants::friction;
    newPos.x = 0;
  } else if (newPos.x >=
             resolution.x / constants::scale - spriteSize.x) {
    velocity.x = -velocity.x * constants::friction;
    newPos.x = resolution.x / constants::scale - spriteSize.x;
  }


  if (newPos.y <= 0) {
    velocity.y = -velocity.y * constants::friction;
    newPos.y = 0;
  } else if (newPos.y >= resolution.y / constants::scale - spriteSize.y) {
    velocity.y = -velocity.y * constants::friction;
    newPos.y = resolution.y / constants::scale - spriteSize.y;
  }
  

  pos.x = newPos.x;
  pos.y = newPos.y;
  */

  return;
}

void EngPlayer::interact(char pressed) {
  if (pressed == ' ')
    return;
}

} // namespace eng