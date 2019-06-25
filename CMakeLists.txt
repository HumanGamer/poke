cmake_minimum_required(VERSION 2.8)

project(poke)

add_executable(poke src/main.cpp)

install(TARGETS poke DESTINATION bin)
