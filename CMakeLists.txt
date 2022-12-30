cmake_minimum_required(VERSION 3.23)
project(university_management)

set(CMAKE_CXX_STANDARD 14)

add_executable(university_management main.cpp manage_classes.cpp manage_classes.h manage_menu.cpp manage_menu.h)
