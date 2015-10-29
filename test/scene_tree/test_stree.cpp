#include "scene_tree/stree.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : public Test
{
	scene_tree::stree uut;
  const scene_tree::stree &const_uut;

	Fixture()
	: uut("badger", 640, 480),
    const_uut(uut)
	{
	}
};

TEST_F(Fixture, TitleIsCorrect)
{
	ASSERT_EQ("badger", uut.title());
}

TEST_F(Fixture, ConstTitleIsCorrect)
{
	ASSERT_EQ("badger", const_uut.title());
}

TEST_F(Fixture, TitleModified)
{
  uut.title() = "fox";
  ASSERT_EQ("fox", uut.title());
}

TEST_F(Fixture, WidthIsCorrect)
{
  ASSERT_EQ(640, uut.width());
}

TEST_F(Fixture, ConstWidthIsCorrect)
{
  ASSERT_EQ(640, const_uut.width());
}

TEST_F(Fixture, HeightIsCorrect)
{
  ASSERT_EQ(480, uut.height());
}

TEST_F(Fixture, ConstHeightIsCorrect)
{
  ASSERT_EQ(480, const_uut.height());
}

TEST_F(Fixture, Equality_Matches)
{
	ASSERT_EQ(scene_tree::stree("badger", 640, 480), uut);
}

TEST_F(Fixture, DifferentTitle_DoesntMatch)
{
	ASSERT_NE(scene_tree::stree("fox", 640, 480), uut);
}

TEST_F(Fixture, DifferentWidth_DoesntMatch)
{
	ASSERT_NE(scene_tree::stree("badger", 42, 480), uut);
}

TEST_F(Fixture, DifferentHeight_DoesntMatch)
{
	ASSERT_NE(scene_tree::stree("badger", 640, 42), uut);
}

