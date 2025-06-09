cmake_minimum_required(VERSION 3.22)

# Set some basic project attributes
project (W09sensors
	VERSION 0.1
	DESCRIPTION "A Hello World Project")

add_compile_options(-Wall -Wextra)

# This project will output an executable file
add_executable(stack stack.cpp)

add_executable(stack-t main-stack-t.cpp) # stack-t.cpp)


