cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)
project(CClicker++ VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CClicker++ src/main.cpp src/clicker.cpp src/colors.cpp src/key.cpp src/prompts.cpp)
target_include_directories(CClicker++ PUBLIC ./include)

set_target_properties(CClicker++ PROPERTIES WIN32_EXECUTABLE YES)
set_target_properties(CClicker++ PROPERTIES RESOURCE "./icon.ico")