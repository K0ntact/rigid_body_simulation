cmake_minimum_required(VERSION 3.25)
project(rigid_body_simulationVS)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2-2.26.5\\x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(rigid_body_simulationVS main.cpp src)
target_link_libraries(rigid_body_simulationVS ${SDL2_LIBRARY})
