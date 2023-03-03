/**
 * @file rgb_byte.c
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
    char hex_str[2];
    uint8_t rgb;

    //
    // Read the hex value from the input string and copy
    // to the local buffer.
    // The input string contains the RGB value in hexa.
    // 2 digits represent an one of the color.
    //

    //
    // Copy 2 digits from the input string and print the
    // respective color in the decimal.
    //

    //
    // RED
    //
    strncpy(hex_str, argv[1], sizeof(hex_str)); // Copy RED ASCII hex value
    argv[1] += 2;                               // skip to next color
    sscanf(hex_str, "%x", &rgb);                // convert ASCII to hex
    printf(PRED"RED:   %d\n"PNRM, rgb);

    //
    // GREEN
    //
    strncpy(hex_str, argv[1], sizeof(hex_str)); // copy GREEN ASCII hex value
    argv[1] += 2;                               // skip to next color
    sscanf(hex_str, "%x", &rgb);                // convert ASCII to hex
    printf(PGRN"GREEN: %d\n"PNRM, rgb);

    //
    // BLUE
    //
    strncpy(hex_str, argv[1], sizeof(hex_str)); // copy BLUE ASCII hex value
    sscanf(hex_str, "%x", &rgb);                // Convert ASCII to hex
    printf(PBLU"BLUE:  %d\n"PNRM, rgb);

    return 0;
}