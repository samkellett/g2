#pragma once

#include <GLFW/glfw3.h>

#include <gmock/gmock.h>

namespace g2 {
namespace tools {

class mockglfw
{
public:
  static mockglfw &instance();

  MOCK_CONST_METHOD5(glfwCreateWindow, GLFWwindow*(int,int,const char*, GLFWmonitor*, GLFWwindow*));
  MOCK_CONST_METHOD1(glfwDestroyWindow, void(GLFWwindow *));

private:
  mockglfw() = default;

  mockglfw(const mockglfw &) = delete;
  mockglfw &operator=(mockglfw) = delete;
};

mockglfw &mockglfw::instance()
{
  static mockglfw instance;

  return instance;
}

} // namespace tools
} // namespace g2

