#include "../include/eng_entity.hpp"

namespace eng {

EngEntity::EngEntity(glm::vec2 p_pos, SDL_Texture *p_tex, Vector2I p_spriteSize) 
  : pos(p_pos), tex(p_tex), spriteSize(p_spriteSize)
{
    currentFrame.x = 0;
    currentFrame.y = 0;

    SDL_QueryTexture(p_tex, nullptr, nullptr, &currentFrame.w, &currentFrame.h);
}

void EngEntity::setCurrentFrame(Vector2I * xy){
  currentFrame.x = xy->x;
  currentFrame.y = xy->y;
}

} // namespace eng