#include "utility/scoped_file.hpp"

#include <gtest/gtest.h>

#include <type_traits>

using namespace g2;

static_assert(! std::is_copy_constructible<utils::scoped_file>{}, "Shouldn't be copyable.");
static_assert(! std::is_copy_assignable<utils::scoped_file>{}, "Shouldn't be copyable.");

static_assert(std::is_move_constructible<utils::scoped_file>{}, "Should be movable.");
static_assert(std::is_move_assignable<utils::scoped_file>{}, "Should be movable.");

TEST(CreateFileWithName, HasCorrectName)
{
  utils::scoped_file uut("badger");

  ASSERT_EQ("badger", uut.path().filename());
}
TEST(CreateFile, FileExists)
{
  utils::scoped_file uut;

  ASSERT_TRUE(boost::filesystem::exists(uut.path()));
}

TEST(CreateFile, OutOfScoped_DoesntExist)
{
  boost::filesystem::path path;

  {
    utils::scoped_file uut;
    path = uut.path();
  }

  ASSERT_FALSE(boost::filesystem::exists(path));
}
