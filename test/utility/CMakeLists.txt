# Unit tests for the ./src/utility directory.

add_subdirectory(ml)

add_test(NAME test_compose COMMAND compose)
add_executable(compose test_compose.cpp)
target_link_libraries(compose
  gmock_main
)

add_test(NAME test_scoped_file COMMAND scoped_file)
add_executable(scoped_file test_scoped_file.cpp)
target_link_libraries(scoped_file
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  gtest_main
)

