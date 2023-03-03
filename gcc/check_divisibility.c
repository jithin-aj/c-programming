/**
 * @file check_divisibility.c
 * @author Jithin A
 * @brief Check whether the number is divisible by the given divisor
 * @version 0.1
 * @date 2022-03-21
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
    int num = 0, div = 0;

    //
    // Read the number and divisor
    //
    num = atoi(argv[1]);
    div = atoi(argv[2]);

    //
    // Check if the number is divisible
    //
    if (num % div) {
        printf("The number %d is NOT divisible by %d", num, div);
    } else {
        printf("The number %d is divisible by %d", num, div);
    }
    return 0;
}