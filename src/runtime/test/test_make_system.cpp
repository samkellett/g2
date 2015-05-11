#include "runtime/make_system.hpp"

#include <gtest/gtest.h>

using namespace g2;

TEST(MakeSystem, CorrectSystemCreated)
{
  const auto expected(runtime::system(scene_tree::stree("badger")));

  runtime::make_system uut;
  ASSERT_EQ(expected, uut(scene_tree::stree("badger")));
}

