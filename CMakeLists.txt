cmake_minimum_required(VERSION 3.10)
project(GameShop)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES
    src/*.cpp
    ui/*.cpp
    main.cpp
)

add_executable(GameShop ${SOURCES})
