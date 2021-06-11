cmake_minimum_required(VERSION 3.5)
project(Hexdump)

set(HexdumpVersionMajor 0)
set(HexdumpVersionMinor 1)
set(HexdumpVersionPatch 0)
set(
  LibrarySources
  src/Hexdump.cpp  
)
set(
  ExecutableSources
  src/Application.cpp
  src/CLI.cpp
  src/CLIArg.cpp
  src/Hexdump.cpp
)

add_library(hexdump ${LibrarySources})
add_executable(Hexdump ${ExecutableSources})

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

set(CPACK_PACKAGE_NAME "Hexdump")
set(CPACK_PACKAGE_VENDOR "dibenso")
set(CPACK_PACKAGE_VERSION_MAJOR "${HexdumpVersionMajor}")
set(CPACK_PACKAGE_VERSION_MINOR "${HexdumpVersionMinor}")
set(CPACK_PACKAGE_VERSION_PATCH "${HexdumpVersionPatch}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Hexdump")
set(CPACK_PACKAGE_DESCRIPTION "A tool to dump and analyze binary files")
set(CPACK_COMPONENTS_ALL applications libraries headers)
set(CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "Hexdump")
set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Headers")
set(CPACK_COMPONENT_APPLICATIONS_DESCRIPTION "A tool to dump and analyze binary files")
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION "Libraries used by Hexdump")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION "C/C++ header files for use with Hexdump")
set(CPACK_COMPONENT_HEADERS_DEPENDS libraries)
set(CPACK_COMPONENT_APPLICATIONS_GROUP "Application")
set(CPACK_COMPONENT_LIBRARIES_GROUP "Development")
set(CPACK_COMPONENT_HEADERS_GROUP "Development")
set(CPACK_COMPONENT_GROUP_DEVELOPMENT_DESCRIPTION "Libraries and headers used by Hexdump application")
set(CPACK_ALL_INSTALL_TYPES Full Developer)
set(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_HEADERS_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_APPLICATIONS_INSTALL_TYPES Full)
 
include(CPack)