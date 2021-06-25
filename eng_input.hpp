#include <SDL2/SDL.h>

namespace eng {
class EngInput {

public:
  static char inputCheck(SDL_Event event);
};
} // namespace eng