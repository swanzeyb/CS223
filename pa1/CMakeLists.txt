cmake_minimum_required(VERSION 3.5.0)
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
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
find_library(NCURSES names ncurses PATHS ${CMAKE_CURRENT_BINARY_DIR}/lib)

add_executable(pa1 main.cpp Component.cpp Lifecycle.cpp Layout.cpp)
target_link_libraries(pa1 ${NCURSES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
