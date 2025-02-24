cmake_minimum_required(VERSION 3.30)
project(computer_enh_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(computer_enh_1 main.cpp
        bin_str_map.cpp
        bin_str_map.h
        bytes.h
        bytes.cpp
        instruction.h
)
