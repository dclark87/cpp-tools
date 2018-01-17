cmake_minimum_required(VERSION 3.9)
project(cpptools)

# Project attributes and env vars.
set(CMAKE_CXX_STANDARD 11)
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(SRCEXT cc)

# Includes
include_directories(${COMMON_INCLUDES})

# Gather (non-main) source files.
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.${SRCEXT})
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.${SRCEXT})

# Add as library
add_library(linkedlist ${SRC_FILES})
# This is needed because CMake doesn't recognize *.cc files as CXX.
# See: https://stackoverflow.com/a/16669141/8826268
set_target_properties(linkedlist PROPERTIES LINKER_LANGUAGE CXX)

# Main executable - link in project libraries.
add_executable(main ${PROJECT_SOURCE_DIR}/src/main.${SRCEXT})
target_link_libraries(main linkedlist)

# Configure unit tests to work with googletest.
add_subdirectory(vendor/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Gather test files
file(GLOB_RECURSE TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.${SRCEXT})
add_executable(test_all ${TEST_SRC_FILES})
target_link_libraries(test_all gtest gtest_main)

#add_test(UnitTests test_all)