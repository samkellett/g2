cmake_minimum_required(VERSION 3.1)
project(g2 CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(MACOSX_RPATH ON)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(G2_SOURCES
  src/galaxy.cpp
)

add_library(${PROJECT_NAME} SHARED ${G2_SOURCES})

target_link_libraries(${PROJECT_NAME}
)
