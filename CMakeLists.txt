cmake_minimum_required(VERSION 3.16.3)

project(clusters VERSION 1.2)

execute_process(COMMAND chmod +x visualizer.py)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Wpedantic -Werror -pedantic-errors)

add_executable(clusters main.cpp)
