cmake_minimum_required(VERSION 3.5)

project (Hexdump)

set(SOURCES
  src/CLI.cpp
  src/CLIArg.cpp
  src/Hexdump.cpp
)

add_executable(Hexdump ${SOURCES})

target_include_directories(
  Hexdump
  PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)