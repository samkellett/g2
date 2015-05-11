#include "scene_tree/load_yml.hpp"

#include "utility/scoped_file.hpp"

#include <gtest/gtest.h>

using namespace g2;

using testing::Test;

struct Fixture : Test
{
  const utils::scoped_file config;

  const scene_tree::load_yml uut;

  Fixture()
  : config{},
    uut{}
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
  ss << uut(path.native());

  ASSERT_EQ("sky: blue", ss.str());
}

