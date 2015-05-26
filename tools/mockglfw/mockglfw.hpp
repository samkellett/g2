#pragma once

#include <GLFW/glfw3.h>

#include <gmock/gmock.h>

namespace g2 {
namespace tools {

class mockglfw
{
public:
  mockglfw();
  static mockglfw *instance;

  MOCK_CONST_METHOD5(glfwCreateWindow,GLFWwindow*(int,int,const char*,GLFWmonitor*,GLFWwindow*));
  MOCK_CONST_METHOD1(glfwDestroyWindow, void(GLFWwindow *));
  MOCK_CONST_METHOD0(glfwInit, int());
  MOCK_CONST_METHOD1(glfwMakeContextCurrent, void(GLFWwindow *));
  MOCK_CONST_METHOD1(glfwSetErrorCallback, GLFWerrorfun(GLFWerrorfun));

private:
  mockglfw(const mockglfw &) = delete;
  mockglfw &operator=(mockglfw) = delete;
};

mockglfw::mockglfw()
{
  instance = this;
}

} // namespace tools
} // namespace g2

