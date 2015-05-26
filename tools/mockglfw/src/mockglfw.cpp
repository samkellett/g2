#include "mockglfw.hpp"

#include <cassert>

using g2::tools::mockglfw;

mockglfw *mockglfw::instance = nullptr;

GLFWwindow *
glfwCreateWindow(int width, int height, const char *title, GLFWmonitor *mon, GLFWwindow *win)
{
  assert(mockglfw::instance);
  return mockglfw::instance->glfwCreateWindow(width, height, title, mon, win);
}

void glfwDestroyWindow(GLFWwindow *window)
{
  assert(mockglfw::instance);
  mockglfw::instance->glfwDestroyWindow(window);
}

int glfwInit()
{
  assert(mockglfw::instance);
  return mockglfw::instance->glfwInit();
}

void glfwMakeContextCurrent(GLFWwindow *window)
{
  assert(mockglfw::instance);
  mockglfw::instance->glfwMakeContextCurrent(window);
}

GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun fn)
{
  assert(mockglfw::instance);
  return mockglfw::instance->glfwSetErrorCallback(fn);
}

