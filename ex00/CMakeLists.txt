cmake_minimum_required(VERSION 3.10)

project(bureaucrat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CPP_COMPILER c++)
# set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

# include(./Bureaucrat.hpp)


add_executable(bureaucrat
main.cpp
Bureaucrat.cpp
)

target_include_directories(bureaucrat PRIVATE .)