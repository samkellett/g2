#include "runtime/make_system.hpp"

#include <gtest/gtest.h>

using namespace g2;

TEST(MakeSystem, CorrectSystemCreated)
{
  const auto expected(runtime::system(scene_tree::stree("badger", 1, 2), nullptr));

  ASSERT_EQ(expected, runtime::make_system(scene_tree::stree("badger", 1, 2)));
}

