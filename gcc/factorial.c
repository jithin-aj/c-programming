/**
 * @file factorial.c
 * @author Jithin A
 * @brief Find the factorial of the given number
 * @version 0.1
 * @date 2022-03-21
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief main
 * Entry point
 *
 * @param argc - argument count
 * @param argv - argument vector
 * @return int - returns 0
 */
int
main (int argc, char *argv[])
{
    int number = 0;
    long fact = 1;

    //
    // Read the number from the console
    //
    number = atoi(argv[1]);

    //
    // Print the factorial of the given number.
    //
    for (int num = number; num > 0; num--) {
        fact *= num;
    }
    printf("Factorial of %d is %ld", number, fact);
    return 0;
}