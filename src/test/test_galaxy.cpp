#include "galaxy.hpp"

#include "utility/scoped_file.hpp"

#include <gtest/gtest.h>

using namespace g2;

struct GalaxyFixture : public testing::Test {
  utils::scoped_file config;

  galaxy uut;

  GalaxyFixture()
  : config{},

    uut{}
  {
  }
};

TEST_F(GalaxyFixture, CallChainWorks)
{
  const auto &path(config.path());

  ASSERT_EQ(1, uut(path.native()));
}
