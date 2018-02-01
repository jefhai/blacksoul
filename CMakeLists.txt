cmake_minimum_required(VERSION 3.9)
project(blacksoul)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-lallegro -lallegro_main")

INCLUDE_DIRECTORIES(  /usr/local/include )
LINK_DIRECTORIES(  /usr/local/lib )

add_executable(blacksoul
        engine.cpp
        engine.h
        main.cpp)
