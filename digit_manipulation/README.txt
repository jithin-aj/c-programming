digit_manipulation

C program to calculate the sum of first and last digit of the given number
---

The project is built on the CMAKE environment. Please go through the build Steps for building and
testing this project.

Cmake version used      : v3.22.1
Minimum version required: v3.10

Cmake reference: https://cmake.org
Cmake tutorial : https://cmake.org/cmake/help/latest/guide/tutorial/

Steps to build the project (Linux platform)
---
Step 1: Create build directory and switch to the build directory
> mkdir build
> cd build

Step 2: Provide path for CMakeLists.txt to configure compiler and build the project.
        In our case it is just one directory below.
> cmake ..

Step 3: Build the project
> cmake --build .

Below is the log shown if successfully built
[ 50%] Building C object CMakeFiles/dig.dir/main.c.o
[100%] Linking C executable dig
[100%] Built target dig

Step 4: Execute the project
> ./dig <input_number>

Output:
./dig 1234
The sum of first and last digit of 1234 is 5
