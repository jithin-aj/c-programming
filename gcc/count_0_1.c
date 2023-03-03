/**
 * @file count_0_1.c
 * @author Jithin A
 * @brief Print the binary format of the given number and count
 * number of 0's and 1's.
 * @version 0.1
 * @date 2022-03-21
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    BIG_ENDIAN,
    LITTLE_ENDIAN
} endian_t;

/**
 * @brief get_endian
 * Function returns the endianess of the machine
 *
 * @return endian_t - endian of the machine
 */
endian_t
get_endian (void) {
    uint32_t num = 1;
    uint8_t *p_num = (uint8_t *)&num;

    //
    // Check whether the value is in LSB or MSB
    //
    if (*p_num) {
        return LITTLE_ENDIAN;
    }
    return BIG_ENDIAN;
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
    int num;
    uint8_t bit_range, count_0, count_1;
    endian_t endian;

    //
    // Get the endianess of the machine
    //
    endian = get_endian();

    //
    // Read the number
    //
    num = atoi(argv[1]);

    //
    // Know the range of the number and
    // display w.r.t 8/16/32-bit binary.
    //
    if (num < 256) {
        bit_range = 8;
    }
    else if (num < 65536) {
        bit_range = 16;
    } else {
        bit_range = 32;
    }

    //
    // Display number in binary format along
    // count number of 0's and 1's
    //! NOTE: Based on the endianess of the machine
    //! and range of the number, display in binary.
    //
    printf("Binary: ");
    if (endian == LITTLE_ENDIAN) {
        for (int8_t bit = bit_range - 1; bit >= 0; bit--) {
            printf("%d", (num >> bit) & 0x01);

            //
            // Count 0's and 1's
            //
            if ((num >> bit & 0x01)) {
                count_1++;
            } else {
                count_0++;
            }
        }
    } else {
        for (uint8_t bit = 32 - bit_range; bit < 32; bit++) {
            printf("%d", (num >> bit) & 0x01);

            //
            // Count 0's and 1's
            //
            if ((num >> bit) & 0x01) {
                count_1++;
            } else {
                count_0++;
            }
        }
    }

    //
    // Print the count
    //
    printf("\n0's: %d\n1's: %d", count_0, count_1);
    return 0;
}
