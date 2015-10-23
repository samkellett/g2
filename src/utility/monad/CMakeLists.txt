# Translation units built in the ./src/utility directory.

translation_unit(
  FILE
    optional.hpp

  TEST test/test_optional_monad.cpp
  TEST_LIBRARIES
    gtest_main
)

