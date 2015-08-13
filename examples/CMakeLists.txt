# CMakeLists to build the examples.
project(examples CXX)

include_directories(
  ${CMAKE_SOURCE_DIR}/src
)

add_executable(basic
  basic.cpp
)

target_link_libraries(basic
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${GLFW_LIBRARIES}
  ${YAMLCPP_LIBRARY}
)

file(COPY basic.yml DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
