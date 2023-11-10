cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(GameOfLife
    src/engine.c
    src/LifReader.c
    main.c
)

target_link_libraries(GameOfLife ${SDL2_LIBRARIES})