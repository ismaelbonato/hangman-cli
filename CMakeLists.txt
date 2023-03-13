cmake_minimum_required(VERSION 3.5)

project(hangman LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    main.cpp
    hangmanthegame.cpp
)

set(HEADERS
    hangmanthegame.h
)

add_executable(hangman ${SRC} ${HEADERS})



install(TARGETS hangman
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
