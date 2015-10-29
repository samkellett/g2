#include "scene_tree/load_yml.hpp"

#include "utility/scoped_file.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : Test
{
  const utils::scoped_file config;

  Fixture()
  : config{}
  {
  	std::ofstream fs;
  	fs.open(config.path().native());
  	fs << "sky: blue" << std::endl;
  }
};

TEST_F(Fixture, LoadYml)
{
  const auto &path(config.path());

  std::ostringstream ss;
  ss << scene_tree::load_yml(path.native());

  ASSERT_EQ("sky: blue", ss.str());
}

