/**
 * @file fibonacci.c
 * @author Jithin A
 * @brief Find the fibonacci serier upto given length
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
    int count, curr_num, prev_num, fibo_number;

    //
    // Read the count limit from the console
    //
    count = atoi(argv[1]);

    //
    // Compute fibonacci series
    //
    curr_num = fibo_number = 1;
    prev_num = 0;
    for ( ; count > 0; count--) {
        printf("%d ", fibo_number);
        fibo_number = curr_num + prev_num;
        prev_num = curr_num;
        curr_num = fibo_number;
    }
    return 0;
}