#include "../include/first_app.hpp"

// std
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {
  eng::FirstApp app{};

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}