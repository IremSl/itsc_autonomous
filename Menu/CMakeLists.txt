
cmake_minimum_required(VERSION 3.10)


project(MenuProject)


set(CMAKE_CXX_STANDARD 11)


set(SOURCES
    main.cpp
    Menu.cpp
)


add_executable(Menu ${SOURCES})
