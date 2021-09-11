cmake_minimum_required(VERSION 3.20)
project(Competitive)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wfloat-equal -fno-sanitize-recover -fstack-protector")

add_executable(main "current.cpp")
