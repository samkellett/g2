# Translation units built in the ./src/utility directory.
add_subdirectory(ml)
add_subdirectory(monad)

translation_unit(
  FILE
    compose.hpp

  TEST test/test_compose.cpp
  TEST_LIBRARIES
    gmock_main
)

translation_unit(
  FILE
    scoped_file.hpp
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}

  TEST test/test_scoped_file.cpp
  TEST_LIBRARIES
    gtest_main
)
