# Translation units built in the ./src directory.
add_subdirectory(scene_tree)
add_subdirectory(utility)

translation_unit(
  FILE
    galaxy.hpp
  DEPENDS
    utility/scoped_file.hpp
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${YAMLCPP_LIBRARY}

  TEST test/test_galaxy.cpp
  TEST_LIBRARIES
    gtest_main
)
