#pragma once

#include "eng_math.hpp"

#include <string>

namespace constants {
const float gravity {9.81f};
const float scale {2.0f};
const std::string windowName {"Space Walk"};
const float accel {0.01f};
const float friction {0.3f};
} // namespace constants
const eng::Vector2I resolution {800, 600};