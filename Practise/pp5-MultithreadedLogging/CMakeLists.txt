cmake_minimum_required(VERSION 3.10)

project(pp5-MultithreadedLogging)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(pp5-MultithreadedLogging src/main.cpp src/Logger.cpp)