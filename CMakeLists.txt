cmake_minimum_required(VERSION 3.17)
project(prg2_labo2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(prg2_labo2 main.c bateau.h bateau.c affichage.h affichage.c)