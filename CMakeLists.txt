cmake_minimum_required(VERSION 3.16)
project(pacman)

set(CMAKE_C_STANDARD 99)

include(FetchContent)

set(RAYLIB_VERSION "4.0.0")
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    URL_HASH SHA256=11f6087dc7bedf9efb3f69c0c872f637e421d914e5ecea99bbe7781f173dc38c
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

file(GLOB ${PROJECT_NAME}_SOURCES src/*.c src/*.h)
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)