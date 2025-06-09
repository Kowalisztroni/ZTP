cmake_minimum_required(VERSION 3.14)
project(Lista2)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_library(tokenizer lib/tokenizer/tokenizer.cpp lib/tokenizer/tokenizer.h)




add_executable(main src/main.cpp)
target_link_libraries(main tokenizer)



add_subdirectory(tests)