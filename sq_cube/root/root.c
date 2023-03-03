/**
 * @file root.c
 * @author Jithin A
 * @brief Check whether the given number is perfect square or cube
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "../common.h"
#include <stdbool.h>
#include "root.h"

/**
 * @brief is_perfect_root
 * Function check the given number is a perfect square/cube using binary search
 *
 * @param num  - number to check
 * @param root - 0: square root
 *               1: cube root
 * @return true  - perfect square/cube root
 * @return false - not a square/cube root
 */
bool is_perfect_root (uint32_t num, uint8_t root)
{
    bool result = false;
    int count = 0;

    //
    // Search for the number, can be done using binary search
    // Start with the second half
    //
    uint32_t end        = num;
    uint32_t start      = num >> 1;
    uint32_t sq_cb_root = 0;

    while (start < end) {
        count++;
        //
        // Check if we have the number
        //
        if (root == SQ_ROOT) {
            sq_cb_root = (start * start);
        } else {
            sq_cb_root = (start * start * start);
        }

        //
        // Check if the number is perfect root
        //
        if (sq_cb_root == num) {
            //
            // Found the number, the given number is perfect root
            //
            result = true;
            break;
        }
        else if (sq_cb_root > num) {
            //
            // Switch to the other side
            //
            end = start;
            start >>= 1;
        }
        else {
            //
            // Search for the number in the current area
            //
            start++;
        }
    }

    printf("Count: %d, number: %d\n", count, start);

    return result;
}
