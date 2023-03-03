/**
 * @file rgb_bit.c
 * @author Jithin A
 * @brief
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Private macros */
#define PNRM  "\033[0;0m"
#define PRED  "\033[1;31m"
#define PGRN  "\033[1;32m"
#define PBLU  "\033[1;34m"

// RGB bit representation
#define BIT_COUNT_RED   5
#define BIT_COUNT_GREEN 6
#define BIT_COUNT_BLUE  5

#define BIT_MASK_RED    0x1F // 0b 0001 1111
#define BIT_MASK_GREEN  0x3F // 0b 0011 1111
#define BIT_MASK_BLUE   0x1F // 0b 0001 1111

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
    char hex_str[4];
    uint16_t hex_rgb;

    //
    // Read the hex value from the input string
    // RGB value is encoded onto a 2 byte value
    // with red as 5 bits green as 6 bits and blue
    // as 5 bits
    //
    strncpy(hex_str, argv[1], sizeof(hex_str));
    sscanf(hex_str, "%x", &hex_rgb);

    //
    // Read values from LSB
    //! NOTE: blue is in LSB
    //

    //
    // BLUE
    //
    printf(PBLU"BLUE:  %d\n"PNRM, (hex_rgb & BIT_MASK_BLUE));
    hex_rgb >>= BIT_COUNT_BLUE; // omit BLUE

    //
    // GREEN
    //
    printf(PGRN"GREEN: %d\n"PNRM, (hex_rgb & BIT_COUNT_GREEN));
    hex_rgb >>= BIT_COUNT_GREEN; // omit GREEN

    //
    // RED
    //
    printf(PRED"RED:   %d\n"PNRM, (hex_rgb & BIT_MASK_RED));

    return 0;
}