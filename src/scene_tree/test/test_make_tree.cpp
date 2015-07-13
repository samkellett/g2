#include "scene_tree/make_tree.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

TEST(MakeTree, ParseYamlIntoSTree)
{
  auto config(YAML::Load(
    "title: badger\n"
    "width: 640\n"
    "height: 480\n"
  ));

  ASSERT_EQ(scene_tree::stree("badger", 640, 480), scene_tree::make_tree(config));
}

