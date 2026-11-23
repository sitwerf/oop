cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(mylib_proj VERSION 0.0.1 LANGUAGES CXX)

# INTERFACE — потому что функции шаблонные и весь код в 5.h
add_library(mylib INTERFACE)