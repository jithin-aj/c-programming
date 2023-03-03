/**
 * @file spell_check.c
 * @author Jithin A
 * @brief Spell check program to replace all the a's with
 * an's if the following word starts with a vowel.
 * @version 0.1
 * @date 2022-03-27
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* Private macros */
#define PNRM  "\x1B[0;0m"
#define PRED  "\x1B[1;31m"
#define PGRN  "\x1B[1;32m"

// Buffer size
#define MAX_INPUT_CHAR_COUNT    40

/**
 * @brief main
 * Entry point
 *
 * @return int - returns 0
 */
int
main (void)
{
    char in_str[MAX_INPUT_CHAR_COUNT] = {0};
    uint8_t in_off = 0;

    //
    // The output string requires additional space for inserting
    // additional characters.
    //
    uint8_t out_off = 0;
    bool b_spell_mis = false;

    //
    // Read the string from the console
    // The max limit is 40 char, but the user can input less than
    // max limit, handle if user enters less that max limit.
    //
    printf("Enter the string. Max 40 characters\n");
    for (uint8_t index = 0; index < MAX_INPUT_CHAR_COUNT; index++) {
        scanf("%c", &in_str[index]);

        //
        // Check if user has entered to new line, if so
        // break and store all the entered char.
        //
        if (in_str[index] == '\n') {
            break;
        }
    }

    //
    // Scan each char and search for 'a' and validate if it is the
    // start of the word or if the following word stars with vowel
    // if so, replace 'a' with "an".
    //
    for (uint8_t index = 0; in_str[index] != '\0'; index++) {
        if (in_str[index] == 'a') {
            //
            // Check if the the next char is a
            // whitespace or another char.
            //
            if (in_str[index + 1] == ' ') {
                switch (in_str[index + 2]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    {
                        //
                        // The word starts with the vowel
                        // replace 'a' with "an".
                        //
                        b_spell_mis = true;
                        strncpy(&out_str[out_off], &in_str[in_off], (index - in_off) - 1);
                        out_off = strlen(out_str);
                        in_off += index
                    }
                    break;

                    default:
                    {
                        //
                        // Skip the scanned chars
                        //
                        index += 2;
                    }
                    break;
                }
            } else {
                index++;
            }
        }
    }

    //
    // Check if any spell corrected
    //
    if (b_spell_mis) {
        printf("%s\n", in_str);
        return 1;
    } else {
        printf(PGRN"No Grammer mistake found\n"PNRM);
        return 0;
    }
}