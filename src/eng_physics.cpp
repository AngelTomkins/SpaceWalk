#include "../include/eng_physics.hpp"

// std
#include <algorithm>
#include <cmath>
#include <glm/ext/vector_float2.hpp>
#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <ostream>

namespace eng {

void PhysicsWorld::step() {
  for (dynamicBody *body : m_bodies) {
    gravity = {0, 0};

    for (dynamicBody *body2 : m_bodies) {
      if (body != body2) {
        glm::vec2 b1MidPos = {
            (body->getPos().x + body->getSpriteSize().x * .5),
            (body->getPos().y + body->getSpriteSize().y * .5)};

        glm::vec2 b2MidPos = {
            (body2->getPos().x + body2->getSpriteSize().x * .5),
            (body2->getPos().y + body2->getSpriteSize().y * .5)};

        float sqrDst = sqrt(pow((b2MidPos.x) - (b1MidPos.x), 2) +
                            pow((b2MidPos.y) - (b1MidPos.y), 2)) /
                       32;
        if (sqrDst < 0.1) break;
        glm::vec2 forceDir = {(b2MidPos.x) - (b1MidPos.x),
                              (b2MidPos.y) - (b1MidPos.y)};
        forceDir = glm::normalize(forceDir);

        body->setForce(body->getForce() + (forceDir * constants::gravity * body->getMass() * body2->getMass() / sqrDst));

      }
    }


    body->setVelocity(body->getVelocity() + body->getForce() / body->getMass());
    body->setPos(body->getPos() + body->getVelocity());

    // std::cout << "Force: " << body->getForce().x << "x" << body->getForce().y
    // << std::endl; std::cout << "pos: " << body->getPos().x << "x" <<
    // body->getPos().y << std::endl; std::cout << "vel: " <<
    // body->getVelocity().x << "x" << body->getVelocity().y << std::endl;

    body->setForce(glm::vec2(0, 0));
  }
}

void PhysicsWorld::addBody(dynamicBody *body) { m_bodies.push_back(body); }

void PhysicsWorld::removeBody(dynamicBody *body) {
  if (!body)
    return;
  auto itr = std::find(m_bodies.begin(), m_bodies.end(), body);
  if (itr == m_bodies.end())
    return;
  m_bodies.erase(itr);
}

} // namespace eng