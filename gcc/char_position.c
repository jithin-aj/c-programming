/**
 * @file char_position.c
 * @author Jithin A
 * @brief Read the character from the console and print it's position.
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
    // Check if the entered character is a character
    // If is a character, display it's position.
    //
    if (ch >= 'A' && ch <= 'Z') {
        printf("Position: %d", (ch - 'A') + 1);
    }
    else if (ch >= 'a' && ch <= 'z') {
        printf("Position: %d", (ch - 'a') + 1);
    } else {
        //
        // Invalid input
        //
        printf("Invalid input\n");
    }
    return 0;
}