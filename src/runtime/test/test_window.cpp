#include "runtime/window.hpp"

#include <mockglfw.hpp>

#include <gmock/gmock.h>

using namespace g2;

using testing::_;

TEST(Fixture, DefaultWindowNullptr)
{
  runtime::window uut;
  ASSERT_EQ(nullptr, static_cast<GLFWwindow *>(uut));
}

TEST(Fixture, WindowAssignedNotNullptr)
{
  EXPECT_CALL(tools::mockglfw::instance(), glfwDestroyWindow(_))
    .Times(1);

  auto *window(reinterpret_cast<GLFWwindow *>(0xf00d));

  runtime::window uut;
  uut = window;

  ASSERT_NE(nullptr, static_cast<GLFWwindow *>(uut));
}

TEST(Fixture, WindowAssignedSavesPointer)
{
  EXPECT_CALL(tools::mockglfw::instance(), glfwDestroyWindow(_))
    .Times(1);

  auto *window(reinterpret_cast<GLFWwindow *>(0xf00d));

  runtime::window uut;
  uut = window;

  ASSERT_EQ(window, static_cast<GLFWwindow *>(uut));
}
