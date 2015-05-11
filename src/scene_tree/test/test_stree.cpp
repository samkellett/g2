#include "scene_tree/stree.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : public Test
{
	scene_tree::stree a;

	Fixture()
	: a("badger")
	{
	}
};

TEST_F(Fixture, TitleIsCorrect)
{
	ASSERT_EQ("badger", a.title());
}

