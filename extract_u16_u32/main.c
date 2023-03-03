/**
 * @file main.c
 * @author Jithin A
 * @brief Given RGB(Red, Green, Blue) value in 2 bytes long where R, G & B is packed in 2 bytes.
 * Extract individual value from the input where R, G & B represents in bits given from input.
 *
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "common.h"

/* Private macros */
#define BITS_IN_BYTE    (8)

/**
 * @brief get_pow
 * Smaller version of calculating the base power of exponent where base and exponent should be
 * small values
 *
 * @param base - base
 * @param exp  - exponent
 * @return uint8_t - return base power exponent result
 */
uint8_t get_pow (uint8_t base, uint8_t exp)
{
    uint8_t pow = 1;
    for (uint8_t itr = 0; itr < exp; itr++) {
        pow *= base;
    }

    return pow;
}

/**
 * @brief ext_u16_u32
 * Extract individual RGB value from the 2 byte value. Given R, G & B bit counts
 *
 * @param rgb     - RGB value in 2bytes
 * @param b_red   - number of bits to represent red
 * @param b_green - number of bits to represent green
 * @param b_blue  - number of bits to represent blue
 * @return uint32_t - return RGB packed into 24 bits
 */
uint32_t ext_u16_u32 (uint16_t rgb, uint8_t b_red, uint8_t b_green, uint8_t b_blue)
{
    uint8_t  red     = 0;
    uint8_t  green   = 0;
    uint8_t  blue    = 0;
    uint32_t u32_rgb = 0;

    //
    // Extract RGB individual value from the received input
    // Calculate number of bits to mask and extract the individuals, where individuals can have
    // 0 - (2^n - 1), n = number of bits it is represented in.
    //
    blue   = rgb & (get_pow(2, b_blue) - 1);
    blue <<= (BITS_IN_BYTE - b_blue);

    //
    // Take off blue
    //
    rgb   >>= b_blue;
    green   = rgb & (get_pow(2, b_green) - 1);
    green <<= (BITS_IN_BYTE - b_green);

    //
    // Take off green
    //
    rgb >>= b_green;
    red   = rgb & (get_pow(2, b_red) - 1);
    red <<= (BITS_IN_BYTE - b_red);

    //
    // Concat individual values into 3 bytes
    //
    u32_rgb = red;

    //
    // Make place for green and concat green
    //
    u32_rgb = (u32_rgb << BITS_IN_BYTE) | green;

    //
    // Make place for blue and concat blue
    //
    u32_rgb = (u32_rgb << BITS_IN_BYTE) | blue;

    return u32_rgb;
}

/**
 * @brief main
 * Entry point to the application
 *
 * @param argc
 * @param argv
 */
void main (int argc, char *argv[])
{
    uint32_t u32_rgb    = 0;
    uint16_t u16_rgb    = 0;
    uint8_t  bits_red   = 0;
    uint8_t  bits_green = 0;
    uint8_t  bits_blue  = 0;

    //
    // Validate we have input to process
    //
    if (argc != 5) {
        printf(PRED"Invalid input\n"PNRM);
        printf("Ex: ""<RGB in hex> " PRED"<Red bits> "PGRN"<Green bits> "PBLU"<blue bits>\n"PNRM);
        return;
    }

    //
    // Get RGB value from input
    //
    u16_rgb = atoi(argv[1]);

    //
    // Get individual bits to pack
    //
    bits_red   = atoi(argv[2]);
    bits_green = atoi(argv[3]);
    bits_blue  = atoi(argv[4]);

    //
    // Extract 3 bytes value from 2 bytes
    //
    u32_rgb = ext_u16_u32(u16_rgb, bits_red, bits_green, bits_blue);
    printf(PRED"Original RGB value : 0x%X\n", u16_rgb);
    printf(PGRN"Extracted RGB value: 0x%X\n"PNRM, u32_rgb);
}
