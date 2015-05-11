# Translation units built in the ./src/scene_tree directory.

translation_unit(
  FILE
    stree.hpp

  TEST test/test_stree.cpp
  TEST_LIBRARIES
    gtest_main
)
