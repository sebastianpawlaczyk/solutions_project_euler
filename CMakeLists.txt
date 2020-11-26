cmake_minimum_required(VERSION 3.10.2)

project(EulerSolutions)

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.3)
    message(FATAL_ERROR "GCC version must be at least 9.3!")
endif()

add_executable(problem125 problem125.cpp)

add_executable(problem225 problem225.cpp)
