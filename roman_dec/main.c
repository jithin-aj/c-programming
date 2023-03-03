/**
 * @file main.c
 * @author Jithin A
 * @brief Convert roman numbers into decimal
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "common.h"

/**
 * @brief main
 * Entry point to the application
 *
 * @param argc - argument count
 * @param argv - argument vector
 */
void main (int argc, char *argv[])
{
    char    *p_str_roman = 0;
    int16_t dec          = 0;
    //
    // Validate we have input to process
    //
    if (argc != 2) {
        printf("Invalid input. Enter correct Roman format.\n");
        return;
    }

    p_str_roman = argv[1];

    dec = get_roman_dec(p_str_roman);

    printf("The decimal value of "PGRN"%s "PNRM"is "PRED"%d \n"PNRM, p_str_roman, dec);
}