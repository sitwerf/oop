cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(test_proj VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# переключатель тестов (5.4)
option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

# обработаем директорию с нашей библиотекой
add_subdirectory(lib)

# создаем цель - исполняемый файл
add_executable(app main.cpp)
# свяжем нашу библиотеку с целью
target_link_libraries(app PUBLIC mylib)
# подключаем директорию с нашей библиотекой
target_include_directories(app PUBLIC ${CMAKE_SOURCE_DIR}/lib)

#   cmake -S . -B build --fresh
#   cmake --build build
#   ./build/app
#   запуск тестов. 
#   1. напрямую программа с тестами     ./build/tests/tests_app
#   2. из папки тестов
#   cd build/tests/
#   ./tests_app        # a. напрямую
#   ctest              # b. через CTest
#   cd ../..
#   assert except           ./build/tests/tests_app --gtest_also_run_disabled_tests --gtest_filter='FailDemo.*'
#   запуск без тестов:    
#   cmake -S . -B build -DBUILD_TESTS=OFF --fresh
#   cmake --build build