# Translation units built in the ./src/utility directory.
add_subdirectory(ml)

translation_unit(
  FILE
    compose.hpp

  TEST test/test_compose.cpp
  TEST_LIBRARIES
    gmock_main
)
