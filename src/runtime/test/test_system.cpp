#include "runtime/system.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : public Test
{
  runtime::system uut;

  Fixture()
  : uut(scene_tree::stree("badger"))
  {
  }
};

TEST_F(Fixture, STreeIsCorrect)
{
  ASSERT_EQ(scene_tree::stree("badger"), uut.tree());
}

TEST_F(Fixture, Equality_Matches)
{
  ASSERT_EQ(runtime::system(scene_tree::stree("badger")), uut);
}

TEST_F(Fixture, DifferentTree_DoesntMatch)
{
  ASSERT_NE(runtime::system(scene_tree::stree("fox")), uut);
}

