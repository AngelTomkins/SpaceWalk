#pragma once

#include "eng_math.hpp"
#include "constants.hpp"
#include "eng_entity.hpp"

#include <vector>
#include <glm/vec2.hpp>
 
namespace eng {

class dynamicBody : public EngEntity{

public:
  void updateVelocity (std::vector<dynamicBody> * bodies);
  dynamicBody(glm::vec2 p_pos, SDL_Texture *p_tex, Vector2I p_spriteSize, float mass);

  glm::vec2 getVelocity(){ return velocity; }
  void setVelocity(glm::vec2 v) { velocity = v; }
  glm::vec2 getForce() { return force; }
  void setForce(glm::vec2 f) {force = f; }
  float getMass() { return mass; }
  


protected:
  void updatePos(std::vector<dynamicBody> *bodies);
  float mass {1};
  glm::vec2 force{0,0};
  float radius;
  glm::vec2 velocity{0,0};
};
class staticBody {


private:
  float mass;
  float radius;
  glm::vec2 velocity;
};

} // namespace eng