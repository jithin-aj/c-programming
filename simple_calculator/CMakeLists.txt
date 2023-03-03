cmake_minimum_required(VERSION 3.10)

project(simple_calculator)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app
    main.c
    simple_calculator.c
)
