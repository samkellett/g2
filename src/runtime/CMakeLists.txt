# Translation units built in the ./src/runtime directory.

translation_unit(
  FILE
    initialise.hpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}

  TEST test/test_initialise.cpp
  TEST_LIBRARIES
    mockglfw
    gmock_main
)

translation_unit(
  FILE
    make_system.hpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}

  TEST test/test_make_system.cpp
  TEST_LIBRARIES
    mockglfw
    gtest_main
)

translation_unit(
  FILE
    system.hpp
  LIBRARIES
    ${YAMLCPP_LIBRARY}

  TEST test/test_system.cpp
  TEST_LIBRARIES
    mockglfw
    gtest_main
)

translation_unit(
  FILE
    window.hpp

  TEST test/test_window.cpp
  TEST_LIBRARIES
    mockglfw
    gtest_main
)

