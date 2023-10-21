cmake_minimum_required(VERSION 3.26)
project(MorseNew)

set(CMAKE_CXX_STANDARD 17)

add_executable(MorseNew main.cpp
        morse_data_and_functions.cpp
        morse_tester.cpp
        morse_data_and_functions.h)
