cmake_minimum_required(VERSION 3.1)
project(g2 CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(MACOSX_RPATH ON)

include(TranslationUnit)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Find all our translation units.
add_subdirectory(src)

# And create our shared library.
add_library(${PROJECT_NAME} SHARED ${g2_SOURCES})

target_link_libraries(${PROJECT_NAME}
)
