cmake_minimum_required(VERSION 3.0.0)
project(pa1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include(ExternalProject)
ExternalProject_Add(ncurses
  DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}
  URL https://github.com/mirror/ncurses/archive/refs/tags/v6.4.tar.gz
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/ncurses-prefix/src/ncurses/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}"
  BUILD_COMMAND "make"
)

add_executable(pa1 main.cpp Component.cpp Menu.cpp Lifecycle.cpp Layout.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
