#include "scene_tree/make_tree.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : Test
{
  scene_tree::make_tree uut;

  Fixture()
  : uut{}
  {
  }
};

TEST_F(Fixture, ParseYamlIntoSTree)
{
  auto config(YAML::Load(
    "title: badger\n"
    "width: 640\n"
    "height: 480\n"
  ));

  ASSERT_EQ(scene_tree::stree("badger", 640, 480), uut(config));
}

