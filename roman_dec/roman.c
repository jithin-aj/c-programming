/**
 * @file roman.c
 * @author Jithin A
 * @brief Convert Roman values into decimal
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "common.h"

/**
 * @brief get_roman_off
 * Get the offset for the given roman number to later map with the equivalent decimal
 *
 * @param r - roman character
 * @return uint8_t - offset for roman to decimal mapping
 */
uint8_t get_roman_off (char r)
{
    switch (r)
    {
        case I:
        {
            return 1;
        }
        break;

        case V:
        {
            return 5;
        }
        break;

        case X:
        {
            return 10;
        }
        break;

        case L:
        {
            return 50;
        }
        break;

        case C:
        {
            return 100;
        }
        break;

        case D:
        {
            return 500;
        }
        break;

        case M:
        {
            return 1000;
        }
        break;

        default:
        {
            //
            // Invalid input, return 0
            //
            return 0;
        }
        break;
    }
}

/**
 * @brief get_roman_dec
 * Convert given roman string into equivalent decimal
 *
 * @param p_str - pointer to the roman string
 * @return int16_t - equivalent decimal
 */
int16_t get_roman_dec (char *p_str)
{
    uint8_t  cur_off = 0;
    uint8_t  nxt_off = 0;
    int16_t  dec     = 0;
    //
    // Read the roman character one after the other.
    // NOTE: The representation of number before 5's and 10's multiples are little different as the
    //       number is subtracted by the next occurring 5's and 10's.
    // So it is better to keep track on the next occurring number also.
    //
    cur_off = get_roman_off(*p_str);
    while (*p_str) {
        //
        // Get the Roman character position from our table
        //
        nxt_off = get_roman_off(*++p_str);

        //
        // Check if my current Roman char position is lesser or greater than the next occurrence
        //
        if ((nxt_off != 255) && (cur_off < nxt_off)) {
            dec -= dec_map[cur_off];
        } else {
            dec += dec_map[cur_off];
        }

        //
        // Switch to next occurrence
        //
        cur_off = nxt_off;
    }

    return dec;
}