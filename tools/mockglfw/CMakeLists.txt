project(mockglfw CXX)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set(${PROJECT_NAME}_SOURCES
  mockglfw.cpp
)

add_library(${PROJECT_NAME} STATIC ${mockglfw_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_RPATH ON)
target_link_libraries(${PROJECT_NAME} gmock)

