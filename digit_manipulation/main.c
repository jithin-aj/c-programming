/**
 * @file main.c
 * @author Jithin A
 * @brief Add the first and last digits from the given input
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "common.h"

/**
 * @brief get_sum_of_first_last_digit
 * Calculate the sum of first and the last digit of the given integer
 * Use modulus to remove digit from lSB one after the other.
 *
 * @param num
 * @return uint8_t
 */
uint8_t get_sum_of_first_last_digit (uint32_t num)
{
    uint8_t ret = 0;

    //
    // Catch the last digit
    //
    ret += num % 10;

    //
    // Go until first digit
    //
    while (num > 9) {
        num /= 10;
    }

    //
    // Sum up with the first digit
    //
    ret += num;

    return ret;
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
    uint32_t num = 0;
    uint8_t  res = 0;

    //
    // Validate we have input to process
    //
    if (argc != 2) {
        printf(PRED"Invalid input\n"PNRM);
        printf("Ex: "PGRN"<Number>\n"PNRM);
        return;
    }

    //
    // Get the input number
    //
    num = atoi(argv[1]);

    //
    // Validate we have positive non zero number
    //
    if (num <= 0) {
        printf("Enter positive number\n");
        return;
    }

    res = get_sum_of_first_last_digit(num);

    printf("The sum of first and last digit of "PRED"%d "PNRM"is "PGRN"%d \n", num, res);
}