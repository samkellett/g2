#include "runtime/system.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : public Test
{
  runtime::system uut;
  const runtime::system &const_uut;

  Fixture()
  : uut(scene_tree::stree("badger", 640, 480), reinterpret_cast<GLFWwindow *>(0xf00d)),
    const_uut(uut)
  {
  }
};

TEST_F(Fixture, TreeIsCorrect)
{
  ASSERT_EQ(scene_tree::stree("badger", 640, 480), uut.tree());
}

TEST_F(Fixture, ConstTreeIsCorrect)
{
  ASSERT_EQ(scene_tree::stree("badger", 640, 480), const_uut.tree());
}

TEST_F(Fixture, WindowIsCorrect)
{
  ASSERT_EQ(reinterpret_cast<GLFWwindow *>(0xf00d), uut.window());
}

TEST_F(Fixture, ConstWindowIsCorrect)
{
  ASSERT_EQ(reinterpret_cast<GLFWwindow *>(0xf00d), const_uut.window());
}

TEST_F(Fixture, WindowModified)
{
  uut.window() = nullptr;
  ASSERT_EQ(nullptr, uut.window());
}

TEST_F(Fixture, Equality_Matches)
{
  scene_tree::stree tree("badger", 640, 480);
  ASSERT_EQ(runtime::system(std::move(tree), reinterpret_cast<GLFWwindow *>(0xf00d)), uut);
}

TEST_F(Fixture, DifferentTree_DoesntMatch)
{
  scene_tree::stree tree("fox", 640, 480);
  ASSERT_NE(runtime::system(std::move(tree), reinterpret_cast<GLFWwindow *>(0xf00d)), uut);
}

TEST_F(Fixture, DifferentWindow_DoesntMatch)
{
  scene_tree::stree tree("badger", 640, 480);
  ASSERT_NE(runtime::system(std::move(tree), nullptr), uut);
}

