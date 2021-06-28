#include "eng_entity.hpp"

namespace eng {

EngEntity::EngEntity(Vector2f p_pos, SDL_Texture *p_tex) 
  : pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;

    SDL_QueryTexture(p_tex, nullptr, nullptr, &currentFrame.w, &currentFrame.h);
}
} // namespace eng