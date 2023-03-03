/**
 * @file overflow_short.c
 * @author Jithin A
 * @brief Find overflow when two short values are added and assigned to
 * another short value
 * @version 0.1
 * @date 2022-03-19
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
    short res, num1, num2;
    bool b_overflow;

    //
    // Read the number from the argument
    //
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

   //
   // Add the given number and display if overflow occurs
   //
   res = num1 + num2;
   b_overflow = ((num1 > num2) ?
                 ((res <= num1) ? true : false) :
                 ((res <= num2) ? true : false));
    if (b_overflow) {
        printf(PRED"Overflow occurred!\n"PNRM);
        printf(PRED"Sum: %d"PNRM, res);
    } else {
        printf(PGRN"Sum: %d\n"PNRM, res);
    }

   return 0;
}
