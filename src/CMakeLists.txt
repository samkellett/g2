# Translation units built in the ./src directory.
add_subdirectory(utility)

translation_unit(
  FILE
    galaxy.cpp

  TEST test/test_galaxy.cpp
  TEST_LIBRARIES
    gtest_main
)
