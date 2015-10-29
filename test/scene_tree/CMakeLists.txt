# Unit tests for the ./src/scene_tree directory.

add_test(NAME test_load_yml COMMAND load_yml)
add_executable(load_yml test_load_yml.cpp)
target_link_libraries(load_yml
  ${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
  ${YAMLCPP_LIBRARY}
  gtest_main
)

add_test(NAME test_make_tree COMMAND make_tree)
add_executable(make_tree test_make_tree.cpp)
target_link_libraries(make_tree
  ${YAMLCPP_LIBRARY}
  gtest_main
)

add_test(NAME test_stree COMMAND stree)
add_executable(stree test_stree.cpp)
target_link_libraries(stree
  gtest_main
)

