# Translation units built in the ./src/scene_tree directory.

translation_unit(
  FILE
    load_yml.hpp
  LIBRARIES
    ${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
    ${YAMLCPP_LIBRARY}

  TEST test/test_load_yml.cpp
  TEST_LIBRARIES
    gtest_main
)

translation_unit(
  FILE
    stree.hpp

  TEST test/test_stree.cpp
  TEST_LIBRARIES
    gtest_main
)
