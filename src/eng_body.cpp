#include "../include/eng_body.hpp"

#include <iostream>
#include <cmath>

namespace eng {

dynamicBody::dynamicBody(glm::vec2 p_pos, SDL_Texture *p_tex,
                         Vector2I p_spriteSize, float p_mass)
    : EngEntity{p_pos, p_tex, p_spriteSize}, velocity{0, 0}, mass(p_mass) {
    }

void dynamicBody::updateVelocity(std::vector<dynamicBody> *bodies) {/*
  for (dynamicBody b1 : *bodies) {
    for (dynamicBody b2 : *bodies) {
      float masses = b1.mass * b2.mass;
      glm::vec2 radiusesPow = {
          (b1.pos.x - b2.pos.x) * (b1.pos.x - b2.pos.x),
          (b1.pos.y - b2.pos.y) * (b1.pos.y - b2.pos.y) };
      glm::vec2 Force = {
          (constants::gravity * (masses / radiusesPow.x)),
          (constants::gravity * (masses / radiusesPow.y))};
        acceleration.x = Force.x / b1.mass;
        acceleration.y = Force.y / b1.mass;
        std::cout << b1.velocity.x << "x" << b1.velocity.y << std::endl;
        if (!isinf(Force.x) || !isinf(Force.y)) {
          if (b1.pos.x > b2.pos.x)
            acceleration.x = -acceleration.x;
          if (b1.pos.y > b2.pos.y)
            acceleration.y = -acceleration.y;
          b1.velocity.x += acceleration.x;
          b1.velocity.y += acceleration.y;
        //   std::cout << b1.velocity.x << "x" << b1.velocity.y << std::endl;
        }
    //   std::cout << Force.x << "x" << Force.y << " " << b1.velocity.x << "x" << b1.velocity.y << std::endl;
    }
    b1.velocity.x = 100.0f;
    b1.velocity.y = 100.0f;
  }
  updatePos(bodies);
  */
}

void dynamicBody::updatePos(std::vector<dynamicBody> *bodies) {
  for (dynamicBody b : *bodies) {
    std::cout << b.pos.x << "x" << b.pos.y << " " << b.velocity.x << "x" << b.velocity.y << std::endl;
    // Vector2f newPos {b.pos.x + b.velocity.x, b.pos.y + b.velocity.y};
    
    glm::vec2 newPos;
    newPos.x = b.pos.x + (b.velocity.x * constants::accel);
    newPos.y = b.pos.y + (b.velocity.y * constants::accel);
    // std::cout << newPos.x << "x" << newPos.y << std::endl;
    b.pos.x = newPos.x;
    b.pos.y = newPos.y;
  }
  
}

} // namespace eng