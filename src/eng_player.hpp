#pragma once
#include "eng_entity.hpp"
#include "constants.hpp"
#include "eng_window.hpp"

namespace eng {
class EngPlayer : public EngEntity {
public:
  EngPlayer(Vector2f p_pos, SDL_Texture* p_tex, EngWindow* engWindow);
  void move(Vector2f &direction);
  void update();

private:
  Vector2f vel;
  EngWindow *engWindow;

  SDL_Texture* textures[8];
  int dir;
};
} // namespace eng