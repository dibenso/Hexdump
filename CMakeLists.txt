cmake_minimum_required(VERSION 3.10)

project(Hexdump, VERSION 1.0)

file(GLOB SOURCES src/*.cpp)

add_executable(Hexdump ${SOURCES})