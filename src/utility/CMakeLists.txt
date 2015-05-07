# Translation units built in the ./src/utility directory.
add_subdirectory(ml)

translation_unit(
  FILE
    variant.hpp

  TEST test/test_variant.cpp
  TEST_LIBRARIES
    gtest_main
)
