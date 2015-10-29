# Unit tests for the ./src/runtime directory.

add_test(NAME test_initialise COMMAND initialise)
add_executable(initialise test_initialise.cpp)
target_link_libraries(initialise
  ${YAMLCPP_LIBRARY}
  mockglfw
  gmock_main
)

add_test(NAME test_make_system COMMAND make_system)
add_executable(make_system test_make_system.cpp)
target_link_libraries(make_system
  ${YAMLCPP_LIBRARY}
  mockglfw
  gtest_main
)

add_test(NAME test_system COMMAND system)
add_executable(system test_make_system.cpp)
target_link_libraries(system
  ${YAMLCPP_LIBRARY}
  mockglfw
  gtest_main
)

add_test(NAME test_window COMMAND window)
add_executable(window test_window.cpp)
target_link_libraries(window
  mockglfw
  gtest_main
)

