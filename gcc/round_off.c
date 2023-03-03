/**
 * @file round_off.c
 * @author Jithin A
 * @brief Round off the given number to it's nearest 10/100/1000...
 * @version 0.1
 * @date 2022-03-16
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
    int num, round_off_val;

    //
    // Read the number from the argument
    //
    num = atoi(argv[1]);
    round_off_val = atoi(argv[2]);

   //
   // Round off the number to the nearest given value
   // Ex:
   // If the number < 50 round down to nearest 100/given value
   // If the number >= 50 round up to nearest 100/given value
   //
   num = ((num + (round_off_val / 2)) / round_off_val) * round_off_val;
   printf("Round off value: %d", num);

   return 0;
}
