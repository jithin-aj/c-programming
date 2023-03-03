/**
 * @file char_or_num.c
 * @author Jithin A
 * @brief Read the character from the console and print
 * whether it is character or a number
 * @version 0.1
 * @date 2022-03-21
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <string.h>

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
    char ch = 0;

    //
    // Validate number of characters entered is only one
    //
    if (argc > 1 || strlen(argv[1]) > 1) {
        printf("Invalid input\n");
        return 0;
    }

    //
    // Read the character from the console
    //
    ch = *argv[1];

    //
    // Check whether the char inputted from the
    // console is a number or a char
    //
    if (ch >= '0' && ch <= '9') {
        printf("The entered character is a number: %c", ch);
    }
    else if ((ch >= 'A' || ch >= 'a') && (ch <= 'Z' || ch <= 'z')) {
        printf("The entered character is a character: %c", ch);
    } else {
        printf("Invalid input\n");
    }
    return 0;
}
