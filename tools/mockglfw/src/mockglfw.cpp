#include "mockglfw.hpp"

using g2::tools::mockglfw;

GLFWwindow *
glfwCreateWindow(int width, int height, const char *title, GLFWmonitor *mon, GLFWwindow *win)
{
  return mockglfw::instance().glfwCreateWindow(width, height, title, mon, win);
}

void glfwDestroyWindow(GLFWwindow *window)
{
  mockglfw::instance().glfwDestroyWindow(window);
}

