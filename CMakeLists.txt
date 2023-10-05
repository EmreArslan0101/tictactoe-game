cmake_minimum_required(VERSION 3.26)
project(tictactoe_game C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(tictactoe_game
        tictactoe.c)
