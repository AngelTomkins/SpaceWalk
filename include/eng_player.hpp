#pragma once

#include "eng_entity.hpp"
#include "constants.hpp"
#include "eng_window.hpp"
#include "eng_body.hpp"

namespace eng {
class EngPlayer : public dynamicBody {
public:
  EngPlayer(glm::vec2 p_pos, SDL_Texture* p_tex, Vector2I p_spriteSize, float mass, EngWindow* engWindow);
  void move(glm::vec2 &direction);
  void update();
  void interact(char pressed);

private:
  EngWindow *engWindow;

  void initSprite();
  int nextFrame{0};
  bool isAcceling = false;
};
} // namespace eng