cmake_minimum_required(VERSION 3.20)
project(Competitive)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RELEASE)
endif()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wfloat-equal -fno-sanitize-recover -fstack-protector")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wshadow -Wfloat-equal -fno-sanitize-recover -fstack-protector")

add_executable(main "current.cpp")
