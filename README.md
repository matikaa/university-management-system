# Univeristy-Management-System

Univeristy Management system build with C++ which allows to manage students, teachers and employees.

## Functions for all members:

- add one
- find one
- show list of specific members
- delete one
- delete all members

## Manage with files:

- read members from file
- save member to file

## Files
You got well-prepared files in one folder. It conatins a few:

- students
- teachers
- employees

## Compile and run the program
You can use CMake with properly data as version or name of your project:

```c
cmake_minimum_required(VERSION 3.23)
project(university_management)

set(CMAKE_CXX_STANDARD 14)

add_executable(university_management main.cpp manage_classes.cpp manage_classes.h manage_menu.cpp manage_menu.h)
```

or compile on Linux:
```c
g++ -Wall -pedantic -g main.cpp manage_menu.cpp manage_classes.cpp -o manage
```
then run:
```c
./manage
```
