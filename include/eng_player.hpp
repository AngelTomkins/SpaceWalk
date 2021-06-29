#pragma once
#include "eng_entity.hpp"
#include "constants.hpp"
#include "eng_window.hpp"

namespace eng {
class EngPlayer : public EngEntity {
public:
  EngPlayer(Vector2f p_pos, SDL_Texture* p_tex, Vector2I p_spriteSize, EngWindow* engWindow);
  void move(Vector2f &direction);
  void update();

private:
  Vector2f vel;
  EngWindow *engWindow;

  void initSprite();
  int nextFrame{0};
  bool isAcceling = false;

  SDL_Texture* textures[8];
};
} // namespace eng