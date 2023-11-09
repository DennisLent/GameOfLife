cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

#Add source files
file(GLOB ENGINE_SOURCES "src/*.c")

#Add main file
set(MAIN_SOURCE main.c)

add_executable(GameOfLife ${ENGINE_SOURCES} ${MAIN_SOURCE})

target_include_directories(GameOfLife PRIVATE "src")

target_link_libraries(GameOfLife PRIVATE m)