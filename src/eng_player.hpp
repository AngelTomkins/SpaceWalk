#pragma once
#include "eng_entity.hpp"
#include "constants.hpp"

namespace eng {
class EngPlayer : public EngEntity {
public:
  EngPlayer(Vector2f p_pos, SDL_Texture* p_tex);
  void move(Vector2f &direction);
  void update();


private:
  Vector2f vel;
};
} // namespace eng