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
    -fcolor-diagnostics

  GCC
    -fipa-pure-const
)

# Prep CTest.
enable_testing()

# Include gtest before we set project warnings as it is rife.
add_subdirectory(ext/gtest)

# Warnings:
add_compiler_flag(CXX
  ALL
    -Werror
    -Wfatal-errors

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-qual
    -Wconversion
    -Wdisabled-optimization
    -Wenum-compare
    -Wfloat-equal
    -Wmissing-declarations
    -Wmissing-include-dirs
    -Wold-style-cast
    -Woverflow
    -Woverloaded-virtual
    -Wpacked
    -Wredundant-decls
    -Wshadow
    -Wswitch-enum
    -Wuninitialized

  GCC
    -Wdate-time
    # -Wformat-signedness
    -Wlogical-op
    -Wmaybe-uninitialized
    -Wsuggest-attribute=format
    -Wsuggest-attribute=noreturn
    -Wsuggest-attribute=pure
    # -Wsuggest-final-types
    # -Wsuggest-final-methods
    # -Wsuggest-override
    -Wuseless-cast
    -Wzero-as-null-pointer-constant
)

# Set up our project's search path.
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 3rd-party code is include as system headers to avoid warnings.
include_directories(SYSTEM
  ${gtest_SOURCE_DIR}/include
)

# Find all our translation units.
add_subdirectory(src)

# And create our shared library.
add_library(${PROJECT_NAME} SHARED ${g2_SOURCES})

target_link_libraries(${PROJECT_NAME}
)
