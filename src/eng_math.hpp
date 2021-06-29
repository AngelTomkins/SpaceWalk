#pragma once

namespace eng {
struct Vector2f {
  Vector2f() : x(0.0f), y(0.0f) {}

  Vector2f(float p_x, float p_y) : x(p_x), y(p_y) {}

  float x, y;
};
struct Vector2I{
  Vector2I(int p_x, int p_y) : x(p_x), y(p_y) {}
  int x, y;
};
} // namespace eng