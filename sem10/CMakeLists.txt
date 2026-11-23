cmake_minimum_required(VERSION 3.14)
project(sem10 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main.cpp Documents.cpp)
