# Unit tests for the ./src/utility/ml directory.

add_test(NAME test_max_element COMMAND max_element)
add_executable(max_element test_max_element.cpp)

