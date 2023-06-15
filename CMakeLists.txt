cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)
project(CClicker++ VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CClicker++ src/main.cpp src/clicker.cpp src/colors.cpp src/key.cpp src/prompts.cpp icon.rc)
target_include_directories(CClicker++ PUBLIC ./include)