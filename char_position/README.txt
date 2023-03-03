Char_pos

C program to find position of the given character
---

The project is built on the CMAKE environment. Please go through the build Steps for building and
testing this project.

Cmake version used      : v3.22.1
Minimum version required: 3.10

Cmake reference: https://cmake.org
Cmake tutorial : https://cmake.org/cmake/help/latest/guide/tutorial/

Steps to build the project (Linux platform)
---
Step 1: Create build directory and switch to the directory
> mkdir build
> cd build

Step 2: Provide path for CMakeLists.txt to configure compiler and build the project.
        In our case it is just one directory below.
> cmake ..

Step 3: Build the project
> cmake --build .

Below is the log shown if successfully built
[ 50%] Building C object CMakeFiles/char_pos.dir/main.c.o
[100%] Linking C executable char_pos
[100%] Built target char_pos

Step 4: Execute the project
> ./char_pos <input_character>

Output:
./char_pos C
Position of C is 3
