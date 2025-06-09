cmake_minimum_required(VERSION 3.22)

# Set some basic project attributes
project (W10stl
	VERSION 0.1
	DESCRIPTION "A Hello World Project")

include(FetchContent)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)


add_compile_options(-Wall -Wextra)

# This project will output an executable file
add_executable(algo algo.cpp)
target_link_libraries(algo PRIVATE fmt::fmt)



