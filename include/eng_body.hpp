#include "eng_math.hpp"

namespace eng {
class dynamicBody {

public:
  void updateVelocity (dynamicBody& bodies);


private:
  float mass;
  float radius;
  Vector2f velocity;
};

} // namespace eng