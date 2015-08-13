cmake_minimum_required(VERSION 2.8)
project(g2 CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(AddCompilerFlag)
include(CreateSyntasticConfig)
include(TranslationUnit)

include(CTest)

# Compiler flags:
add_compiler_flag(CXX
  ALL
    -std=c++1y
    -fno-rtti
    # -fvisibility=hidden

  CLANG
    -stdlib=libc++
    -fcolor-diagnostics
    -Wno-gnu-string-literal-operator-template

  GCC
    -fipa-pure-const
)

# Internal dependencies.
add_subdirectory(ext/gmock)

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

# Prep CTest.
enable_testing()

# External project dependencies.
find_package(Boost 1.58 EXACT REQUIRED COMPONENTS filesystem system)
find_package(GLFW REQUIRED)
find_package(Meta REQUIRED)
find_package(YamlCpp REQUIRED)

# Set up our project's search path.
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src

  ${CMAKE_CURRENT_SOURCE_DIR}/tools
)

# 3rd-party code is include as system headers to avoid warnings.
include_directories(SYSTEM
  ${Boost_INCLUDE_DIRS}
  ${GLFW_INCLUDE_DIR}
  ${Meta_INCLUDE_DIR}
  ${YAMLCPP_INCLUDE_DIR}

  ext/gtest/include
  ext/gmock/include
)

link_directories(
  ${Boost_LIBRARY_DIRS}
)

# Create a sytastic config file that contains our include directories.
#create_syntastic_config()

# Find all our translation units.
add_subdirectory(src)

# Tools.
add_subdirectory(tools)

# And create our shared library.
# add_library(${PROJECT_NAME} SHARED ${g2_SOURCES})

# set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_RPATH ON)

# target_link_libraries(${PROJECT_NAME}
#   ${YAMLCPP_LIBRARY}
# )
