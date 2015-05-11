#include "scene_tree/stree.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : public Test
{
	scene_tree::stree uut;

	Fixture()
	: uut("badger")
	{
	}
};

TEST_F(Fixture, TitleIsCorrect)
{
	ASSERT_EQ("badger", uut.title());
}

TEST_F(Fixture, Equality_Matches)
{
	ASSERT_EQ(scene_tree::stree("badger"), uut);
}

TEST_F(Fixture, DifferentTitle_DoesntMatch)
{
	ASSERT_NE(scene_tree::stree("fox"), uut);
}
