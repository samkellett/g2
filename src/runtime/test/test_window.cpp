#include "runtime/window.hpp"

#include <gtest/gtest.h>

using namespace g2;

TEST(Fixture, DefaultWindowNullptr)
{
  runtime::window uut;
  ASSERT_EQ(nullptr, static_cast<GLFWwindow *>(uut));
}

TEST(Fixture, WindowAssignedNotNullptr)
{
  glfwInit();
  auto *window(glfwCreateWindow(1, 2, "", nullptr, nullptr));

  runtime::window uut;
  uut = window;

  ASSERT_NE(nullptr, static_cast<GLFWwindow *>(uut));
}

TEST(Fixture, WindowAssignedSavesPointer)
{
  glfwInit();
  auto *window(glfwCreateWindow(1, 2, "", nullptr, nullptr));

  runtime::window uut;
  uut = window;

  ASSERT_EQ(window, static_cast<GLFWwindow *>(uut));
}
