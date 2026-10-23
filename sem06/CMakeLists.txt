cmake_minimum_required(VERSION 3.14)
project(sem06 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(app main.cpp TextDocument.cpp)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests tests.cpp TextDocument.cpp)
target_link_libraries(tests GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)

#   cmake -S . -B build --fresh
#   cmake --build build
#   ./build/app
#   ./build/tests
