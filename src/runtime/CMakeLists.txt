# Translation units built in the ./src/runtime directory.

translation_unit(
  FILE
    make_system.hpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}

  TEST test/test_make_system.cpp
  TEST_LIBRARIES
    gtest_main
)

translation_unit(
  FILE
    system.hpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}

  TEST test/test_system.cpp
  TEST_LIBRARIES
    gtest_main
)

