cmake_minimum_required(VERSION 3.12)
project(Competitive)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow")

add_executable(main "current.cpp")
