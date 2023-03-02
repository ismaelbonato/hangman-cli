cmake_minimum_required(VERSION 3.5)

project(hangman LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hangman main.cpp)

install(TARGETS hangman
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
