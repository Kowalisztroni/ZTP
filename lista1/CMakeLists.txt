cmake_minimum_required(VERSION 3.10)
project(lista1)


add_library(hello lib/hello/hello.cpp)


add_executable(prog1 src/prog1/main.cpp)
target_link_libraries(prog1 hello)

add_executable(prog2 src/prog2/main.cpp)
target_link_libraries(prog2 hello)