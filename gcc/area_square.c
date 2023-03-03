/**
 * @file area_square.c
 * @author Jithin A
 * @brief Find the area of square from the given parameter-
 * There is a circle inscribed in a square such that all sides touch the
 * circumference of the circle. Program calculate the area inside the
 * square excluding the circle if the size of the square is given as an
 * input.
 * @version 0.1
 * @date 2022-03-19
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Private macros */
#define PI  (3.1415f)

/**
 * @brief main
 * Entry point
 *
 * @param argc - argument count
 * @param argv - argument vector
 * @return int - returns 0
 */
int
main (int argc, char **argv)
{
    //
    // To find the area of the square excluding circle inscribed in a square,
    // we need to find the area of a circle and subtract with the area of the
    // square.
    // Since we know the circumference of the circle touches all sides of the
    // square it means the diameter of the circle is equal to the side of the
    // square.
    // First calculate the side of the square from the given size of the square
    // and calculate the area of the circle.
    //
    double side, radius, square_size, area_square, area_circle;

    //
    // Read the size of the square from the argument
    //
    square_size = atof(argv[1]);

    //
    // Calculate the side of the square.
    //
    side = sqrt(square_size);

    //
    // Calculate the radius of the circle from the side to calculate area of
    // the circle.
    //
    radius = side / 2; // side is equal to diameter of the circle.
    area_circle = PI * radius * radius;

    //
    // Calculate area of the square excluding circle.
    //
    area_square = square_size - area_circle;
    printf("Area of the square excluding circle: %lf cm^2", area_square);

    return 0;
}
