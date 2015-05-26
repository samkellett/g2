#include "runtime/window.hpp"

#include <mockglfw.hpp>

#include <gmock/gmock.h>

using namespace g2;

using testing::_;
using testing::Mock;
using testing::StrictMock;
using testing::Test;

struct WindowFixture : public Test
{
  StrictMock<tools::mockglfw> mockglfw;

  WindowFixture() = default;
};

TEST_F(WindowFixture, DefaultWindowNullptr)
{
  runtime::window uut;
  ASSERT_EQ(nullptr, static_cast<GLFWwindow *>(uut));
}

TEST_F(WindowFixture, WindowAssignedNotNullptr)
{
  EXPECT_CALL(mockglfw, glfwDestroyWindow(_))
    .Times(1);

  auto *window(reinterpret_cast<GLFWwindow *>(0xf00d));

  runtime::window uut;
  uut = window;

  ASSERT_NE(nullptr, static_cast<GLFWwindow *>(uut));
}

TEST_F(WindowFixture, WindowAssignedSavesPointer)
{
  EXPECT_CALL(mockglfw, glfwDestroyWindow(_))
    .Times(1);

  auto *window(reinterpret_cast<GLFWwindow *>(0xf00d));

  runtime::window uut;
  uut = window;

  ASSERT_EQ(window, static_cast<GLFWwindow *>(uut));
}

TEST_F(WindowFixture, DestroyWindow_DestroysCorrectAddress)
{
  auto *window(reinterpret_cast<GLFWwindow *>(0xf00d));

  EXPECT_CALL(mockglfw, glfwDestroyWindow(window))
    .Times(1);

  runtime::window uut(window);
}

