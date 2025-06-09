cmake_minimum_required(VERSION 3.22)

# Set some basic project attributes
project (W-05-operatory
	VERSION 0.1
	DESCRIPTION "Przeciążanie operatorów")

set (CMAKE_CXX_STANDARD 23)

# This project will output an executable file
add_executable( operatory main.cpp )

target_compile_options(operatory PRIVATE -Wall -Wextra)
