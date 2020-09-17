cmake_minimum_required(VERSION 3.16)
project(rayTracer)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(rayTracer main.cpp vec3.hpp color.cpp color.hpp ray.hpp camera.hpp sphere.hpp visibleObject.hpp pointRecord.cpp pointRecord.hpp)