#pragma once

#include "runtime/glfw_error.hpp"
#include "runtime/system.hpp"

#include <GLFW/glfw3.h>

namespace g2 {
namespace runtime {

struct initialise
{
  initialise() = default;

  system operator()(system env)
  {
    glfwSetErrorCallback(glfw_error_callback);

    if (! glfwInit()) {
      throw glfw_error(-1, "Could not initialise GLFW.");
    }

    const auto &tree(env.tree());
    env.window() = glfwCreateWindow(
      tree.width(),
      tree.height(),
      tree.title().c_str(),
      nullptr,
      nullptr
    );

    if (! env.window()) {
      throw glfw_error(-2, "Could not create GLFW window.");
    }

    glfwMakeContextCurrent(env.window());

    return std::move(env);
  }
};

} // namespace runtime
} // namespace g2

