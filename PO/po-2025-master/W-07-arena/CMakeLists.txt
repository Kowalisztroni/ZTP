cmake_minimum_required(VERSION 3.22)

project (W-07-arena VERSION 0.1)

set (CMAKE_CXX_STANDARD 20)

add_executable( arena main.cpp Unit.cpp Ogre.cpp Dwarf.cpp ArenaManager.cpp Witcher.cpp)

target_compile_options(arena PRIVATE -Wall -Wextra)
