#pragma once

#include <glm/ext/vector_float2.hpp>
#include <vector>

#include "eng_body.hpp"

namespace eng {
class PhysicsWorld {
public:
  void addBody (dynamicBody* body);
  void removeBody (dynamicBody* body);

  void step();

private:
  std::vector<dynamicBody*> m_bodies;
  glm::vec2 gravity;

};

}