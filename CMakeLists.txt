cmake_minimum_required(VERSION 3.14)
project(HeapProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Automatically fetch Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include directories
include_directories(include)

# Source files
add_library(heap src/heap.cpp)

# Test executable
add_executable(test_heap tests/test_heap.cpp)
target_link_libraries(test_heap heap gtest gtest_main)

# Add test
add_test(NAME HeapTests COMMAND test_heap)

# Custom target to run tests
add_custom_target(run_tests
  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
  DEPENDS test_heap
)