/**
 * @file main.c
 * @author Jithin A
 * @brief Print the input character position in A - Z
 * @version 0.1
 * @date 2022-12-07
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "common.h"

/**
 * @brief get_char_pos
 * Return the position of the requested character in A - Z irrespective of it's case
 *
 * @param ch
 * @return uint8_t
 */
uint8_t get_char_pos (char ch)
{
    uint8_t pos = 0;

    //
    // Check if the requested character is uppercase or lowercase as we have different ASCII value
    //
    if ((ch >= 'a') && (ch <= 'z')) {
        pos = (ch - 'a') + 1;
    }
    else if ((ch >= 'A') && (ch <= 'Z')) {
        pos = (ch - 'A') + 1;
    }

    return pos;
}

/**
 * @brief main
 * Entry point to the application
 *
 * @param argc - argument count
 * @param argv - argument vector
 */
void main (int argc, char *argv[])
{
    char    ch  = 0;
    uint8_t pos = 0;

    //
    // Validate we have input to process
    //
    if (argc != 2) {
        printf("Invalid input, enter single character.\n");
        return;
    }

    //
    // Get the input
    //
    ch = *argv[1];

    pos = get_char_pos(ch);
    printf("Position of " PGRN "%C " PNRM "is " PRED "%d \n"PNRM, ch, pos);
}
