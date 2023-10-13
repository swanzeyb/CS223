cmake_minimum_required(VERSION 3.5.0)
project(cs223 VERSION 0.1.0 LANGUAGES C CXX)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

include(CTest)
enable_testing()

add_subdirectory(pa2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
