/**
 * @file main.c
 * @author Jithin A
 * @brief Given RGB(Red, Green, Blue) value in 3 bytes long where R, G & B is 1 byte each
 * Zip the 3 byte value to 2 byte with R is represented in 5-bits, G is 5-bits and B is 6-bits
 *
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Private macros */
#define BITS_IN_BYTE    (8)

/**
 * @brief zip_u32_u16
 * Zip received 3 byte value into 2 bytes. Pack the RGB bits as requested
 *
 * @param rgb     - RGB value in 3bytes
 * @param b_red   - number of bits to represent red
 * @param b_green - number of bits to represent green
 * @param b_blue  - number of bits to represent blue
 * @return uint16_t - return RGB packed into 16 bits
 */
uint16_t zip_u32_u16 (uint32_t rgb, uint8_t b_red, uint8_t b_green, uint8_t b_blue)
{
    uint8_t  red     = 0;
    uint8_t  green   = 0;
    uint8_t  blue    = 0;
    uint16_t u16_rgb = 0;

    //
    // Extract RGB individual value from the received input
    //
    blue  = rgb & 0xff;
    green = (rgb >> 8)  & 0xff;
    red   = (rgb >> 16) & 0xff;

    //
    // Since we now have individual values, represent w.r.t it's bits size
    // Since we can represent values from 0 - (2^n - 1) where n is number bits to represent the
    // given color code, subtract 1 to round it off.
    // Otherwise it will round it up to the nearest integer value
    //
    red   = (red   >> (BITS_IN_BYTE - b_red));
    green = (green >> (BITS_IN_BYTE - b_green));
    blue  = (blue  >> (BITS_IN_BYTE - b_blue));

    printf("Red  : 0x%X\n", red);
    printf("Green: 0x%X\n", green);
    printf("Red  : 0x%X\n", blue);

    //
    // Concat individual values into 2 bytes
    //
    u16_rgb = red;

    //
    // Make place for green and concat green
    //
    u16_rgb = (u16_rgb << b_green) | green;

    //
    // Make place for blue and concat blue
    //
    u16_rgb = (u16_rgb << b_blue) | blue;

    return u16_rgb;
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
    // Get RGB value from input
    //
    u32_rgb = atoi(argv[1]);

    //
    // Get individual bits to pack
    //
    bits_red   = atoi(argv[2]);
    bits_green = atoi(argv[3]);
    bits_blue  = atoi(argv[4]);

    //
    // Zip 3 bytes received value into 2 bytes
    //
    u16_rgb = zip_u32_u16(u32_rgb, bits_red, bits_green, bits_blue);
    printf("Original RGB value: 0x%X\n", u32_rgb);
    printf("Zip RGB value     : 0x%X\n", u16_rgb);
}