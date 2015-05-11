# Translation units built in the ./src directory.
add_subdirectory(utility)

translation_unit(
  FILE
    galaxy.cpp
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}

  TEST test/test_galaxy.cpp
  TEST_LIBRARIES
    gtest_main
)
