cmake_minimum_required(VERSION 3.1)
project(g2 CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(MACOSX_RPATH ON)

include(AddCompilerFlag)
include(TranslationUnit)

include(CTest)

# Compiler flags:
add_compiler_flag(CXX
  ALL
    -std=c++1y
    -fno-rtti
    -fvisibility=hidden

  CLANG
    -stdlib=libc++
)

# Warnings:
add_compiler_flag(CXX
  ALL
    -Werror

    -Wall
    -Wextra
    -pedantic

    -Wold-style-cast
    -Woverloaded-virtual
    -Wpointer-arith
    -Wcast-qual
    -Woverflow
    -Wmissing-declarations
    -Wredundant-decls

    # For gtest...
    -Wno-missing-field-initializers
)

# Prep CTest and GTest to do their thing.
enable_testing()
add_subdirectory(ext/gtest)

# Set up our project's search path.
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include

  ${gtest_SOURCE_DIR}/include
)

# Find all our translation units.
add_subdirectory(src)

# And create our shared library.
add_library(${PROJECT_NAME} SHARED ${g2_SOURCES})

target_link_libraries(${PROJECT_NAME}
)
