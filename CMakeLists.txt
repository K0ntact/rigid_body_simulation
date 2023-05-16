cmake_minimum_required(VERSION 3.25)
project(rigid_body_simulation)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2-2.26.5\\x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "SDL2_image-2.6.3\\x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
include_directories(include)

add_executable(rigid_body_simulation main.cpp src include/game.hpp src/game.cpp src/particle2d.cpp src/vector2.cpp src/vector3.cpp src/particle3d.cpp)
target_link_libraries(rigid_body_simulation ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
