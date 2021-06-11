cmake_minimum_required(VERSION 3.5)
project(Hexdump)

add_library(hexdump src/Hexdump.cpp)

add_executable(
  Hexdump
  src/Application.cpp
  src/CLI.cpp
  src/CLIArg.cpp
  src/Hexdump.cpp
)

install(
  TARGETS hexdump
  ARCHIVE
  DESTINATION lib
  COMPONENT libraries
)
install(
  TARGETS Hexdump
  RUNTIME
  DESTINATION bin
  COMPONENT applications
)
install(
  FILES src/Hexdump.h
  DESTINATION include
  COMPONENT headers
)

set (CPACK_PACKAGE_NAME "Hexdump")
set (CPACK_PACKAGE_VENDOR "CMake.org")
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "Hexdump - A tool to dump and analyze binary files")
set (CPACK_PACKAGE_VERSION "0.1.0")
set (CPACK_PACKAGE_INSTALL_DIRECTORY "Hexdump")

set (CPACK_COMPONENTS_ALL applications libraries headers)
set (CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "Hexdump")
set (CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
set (CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Headers")

set (CPACK_COMPONENT_APPLICATIONS_DESCRIPTION
  "Hexdump - A tool to dump and analyze binary files")
set (CPACK_COMPONENT_LIBRARIES_DESCRIPTION
  "Libraries used by Hexdump")
set (CPACK_COMPONENT_HEADERS_DESCRIPTION
  "C/C++ header files for use with Hexdump")

set (CPACK_COMPONENT_HEADERS_DEPENDS libraries)

set(CPACK_COMPONENT_APPLICATIONS_GROUP "Runtime")
set(CPACK_COMPONENT_LIBRARIES_GROUP "Development")
set(CPACK_COMPONENT_HEADERS_GROUP "Development")

set(CPACK_COMPONENT_GROUP_DEVELOPMENT_DESCRIPTION
   "Tool to dump and analyze binary files")

set(CPACK_ALL_INSTALL_TYPES Full Developer)
set(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_HEADERS_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_APPLICATIONS_INSTALL_TYPES Full)
 
include(CPack)