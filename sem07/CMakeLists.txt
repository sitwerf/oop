cmake_minimum_required(VERSION 3.14)
project(sem07 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(app main.cpp TextDocument.cpp)

#   cmake -S . -B build --fresh
#   cmake --build build
#   ./build/app 1    создание / копирование / присваивание
#   ./build/app 2    vector, list, set
#   ./build/app 3    ввод с исключениями
#   ./build/app 4    шаблонный класс
