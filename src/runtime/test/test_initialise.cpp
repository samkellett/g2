#include "runtime/initialise.hpp"

#include "runtime/make_system.hpp"

#include <mockglfw/mockglfw.hpp>

#include <gmock/gmock.h>

using namespace g2;

using testing::_;
using testing::InSequence;
using testing::Return;
using testing::StrEq;
using testing::NiceMock;

struct InitialiseFixture : testing::Test
{
  NiceMock<tools::mockglfw> mockglfw;

  scene_tree::stree tree;
  runtime::system env;

  runtime::initialise uut;

  InitialiseFixture()
  : mockglfw(),

    tree("badger", 1, 2),
    env(runtime::make_system()(std::move(tree))),

    uut()
  {
    ON_CALL(mockglfw, glfwSetErrorCallback(&glfw_error_callback))
      .WillByDefault(Return(nullptr));

    ON_CALL(mockglfw, glfwInit())
      .WillByDefault(Return(GL_TRUE));

    ON_CALL(mockglfw, glfwCreateWindow(_, _, _, _, _))
      .WillByDefault(Return(reinterpret_cast<GLFWwindow *>(0xf00d)));
  }
};

TEST_F(InitialiseFixture, SetsErrorCallback)
{
  EXPECT_CALL(mockglfw, glfwSetErrorCallback(&glfw_error_callback))
    .Times(1);

  uut(std::move(env));
}

TEST_F(InitialiseFixture, InitTrue_NoThrow)
{
  EXPECT_CALL(mockglfw, glfwInit())
    .Times(1);

  ASSERT_NO_THROW({
    uut(std::move(env));
  });
}

TEST_F(InitialiseFixture, InitFalse_ThrowsGlfwError)
{
  EXPECT_CALL(mockglfw, glfwInit())
    .WillOnce(Return(GL_FALSE));

  ASSERT_THROW({
    uut(std::move(env));
  }, glfw_error);
}

TEST_F(InitialiseFixture, InitFalse_GlfwErrorCodeMinus1)
{
  EXPECT_CALL(mockglfw, glfwInit())
    .WillOnce(Return(GL_FALSE));

  try {
    uut(std::move(env));
  } catch(glfw_error &e) {
    ASSERT_EQ(-1, e.error());
  }
}

TEST_F(InitialiseFixture, CreateWindowCalledWithEnvArgs_NoThrow)
{
  const auto &tree(env.tree());
  EXPECT_CALL(mockglfw, glfwCreateWindow(
    tree.width(),
    tree.height(),
    StrEq(tree.title()),
    nullptr,
    nullptr))
      .Times(1);

  ASSERT_NO_THROW({
    uut(std::move(env));
  });
}

TEST_F(InitialiseFixture, CreateWindowReturnsNull_ThrowsGlfwError)
{
  EXPECT_CALL(mockglfw, glfwCreateWindow(_, _, _, _, _))
    .WillOnce(Return(nullptr));

  ASSERT_THROW({
    uut(std::move(env));
  }, glfw_error);
}

TEST_F(InitialiseFixture, CreateWindowReturnsNull_GlfwErrorCodeMinus2)
{
  EXPECT_CALL(mockglfw, glfwCreateWindow(_, _, _, _, _))
    .WillOnce(Return(nullptr));

  try {
    uut(std::move(env));
  } catch(glfw_error &e) {
    ASSERT_EQ(-2, e.error());
  }
}

TEST_F(InitialiseFixture, MakeContextCurrentCalledWithWindowPointer)
{
  InSequence s;

  EXPECT_CALL(mockglfw, glfwCreateWindow(_, _, _, _, _))
    .WillOnce(Return(reinterpret_cast<GLFWwindow *>(0xbeef)));

  EXPECT_CALL(mockglfw, glfwMakeContextCurrent(reinterpret_cast<GLFWwindow *>(0xbeef)))
    .Times(1);

  uut(std::move(env));
}

TEST_F(InitialiseFixture, NewEnv_ExpectedTree)
{
  const scene_tree::stree new_tree("badger", 1, 2);

  const auto &new_env(uut(std::move(env)));
  ASSERT_EQ(new_tree, new_env.tree());
}

TEST_F(InitialiseFixture, NewEnv_ExpectedWindow)
{
  const runtime::window new_window(reinterpret_cast<GLFWwindow *>(0xf00d));

  const auto &new_env(uut(std::move(env)));
  ASSERT_EQ(new_window, new_env.window());
}

