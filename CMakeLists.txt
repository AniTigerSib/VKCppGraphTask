cmake_minimum_required(VERSION 3.20)
project(VKCppGraphTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(VKCppGraphTask src/main.cpp
        src/graph.h
        src/graph.cpp)
