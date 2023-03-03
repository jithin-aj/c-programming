/**
 * @file bit_invert.c
 * @author Jithin A
 * @brief Invert the bits of the given number and display
 * the inverted number
 * @version 0.1
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Private macros */
#define PNRM  "\x1B[0;0m"
#define PRED  "\x1B[1;31m"
#define PGRN  "\x1B[1;32m"

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
    uint32_t num;

    //
    // Read the number from the console
    //
    num = atoi(argv[1]);

    //
    // Since the range of number can be 2^32 - 1
    // scan the number and it's exact range
    // to display the invert of the given number
    //
    if (num < 256) {
        printf("The inverted number: %d", ~(num) & 0x000000FF);
    }
    else if (num < 65536) {
        printf("The inverted number: %d", ~(num) & 0x0000FFFF);
    } else {
        printf("The inverted number: %d", ~num);
    }

    return 0;
}
