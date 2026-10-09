cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(my_tests_proj VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# включаем тесты
enable_testing()
# создаем цель - исполняемый файл
add_executable(tests_app test.cpp)
# подключаем к цели библиотеки
target_link_libraries(tests_app PUBLIC GTest::gtest_main)
target_link_libraries(tests_app PUBLIC mylib)
# подключаем директорию с нашей библиотекой
target_include_directories(tests_app PUBLIC ${CMAKE_SOURCE_DIR}/lib)
# подключаем GoogleTest
include(GoogleTest)
# чтобы выполнялись все тесты
gtest_discover_tests(tests_app)