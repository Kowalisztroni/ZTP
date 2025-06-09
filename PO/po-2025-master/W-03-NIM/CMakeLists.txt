cmake_minimum_required(VERSION 3.22)

# Set some basic project attributes
project (W-03-NIM
	VERSION 0.1
	DESCRIPTION "NIM Game")

set (CMAKE_CXX_STANDARD 23)

# This project will output an executable file
add_executable(nimgame main.cpp Plansza.cpp Gracz.cpp Gra.cpp)

target_compile_options(nimgame PRIVATE -Wall -Wextra)
