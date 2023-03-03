/**
 * @file main.c
 * @author Jithin A
 * @brief Round off the given number to it's nearest given value
 * @version 0.2
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "common.h"

/**
 * @brief get_round_off
 * Round off the number to the nearest given value
 * Ex:
 * If the number is less than (round_off_val / 2), round down to nearest value as it lies in
 * lower half.
 * If the number greater than (round_off_val / 2), round up to nearest value as it lies in
 * upper half
 *
 * @param num
 * @param round_off
 * @return int
 */
int get_round_off (int num, int round_off)
{
    return ((num + (round_off >> 1)) / round_off) * round_off;
}

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
    int num           = 0;
    int round_off_val = 0;
    int result        = 0;

    //
    // Validate we have input to process
    //
    if (argc != 3) {
        printf(PRED"Invalid input\n"PNRM);
        printf(PGRN"Enter a number along round off value\n"PNRM);
        return 0;
    }

    //
    // Read the number from the argument
    //
    num = atoi(argv[1]);
    round_off_val = atoi(argv[2]);

    //
    // Get the round off value
    //
    result = get_round_off(num, round_off_val);
    printf(PRED "%d " PNRM "is rounded to " PGRN "%d \n"PNRM, num, result);

    return 0;
}
