cmake_minimum_required(VERSION 3.25.1)
project(CPU)

include_directories(./headers)

file(GLOB SOURCE ./sources/*.cpp)

add_executable(cpu ${SOURCE})
