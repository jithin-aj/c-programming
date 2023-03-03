/**
 * @file main.c
 * @author Jithin A
 * @brief Capitalize the first and last letter of the word in a sentence if it is a vowel.
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief is_vowel
 * Function checks the first and last letter of the given word for vowels
 * Return if both the first and
 *
 * @param p_word     - pointer to the word
 * @param char_count - number of characters in the word
 * @return true      - both first and last letter is vowel
 * @return false     - not a vowel
 */
bool is_vowel (char *p_word, uint8_t char_count)
{
    bool first_char = false;
    bool last_char  = false;
    char vowels[] = "a, e, i, o, u";

    for (uint8_t off = 0; off < strlen(vowels); off++) {
        //
        // First character
        //
        if (p_word[0] == vowels[off]) {
            first_char = true;
        }

        //
        // Last character
        //
        if (p_word[char_count - 1] == vowels[off]) {
            last_char = true;
        }
    }

    return (first_char && last_char);
}

/**
 * @brief caps_char
 * Capitalize the first and last letter in the word
 *
 * @param p_word     - pointer to the word
 * @param char_count - number of characters in the word
 */
void caps_char (char *p_word, uint8_t char_count, char *p_out)
{
    //
    // Copy the given word into the output buffer and change the case on the output buffer
    //
    strcpy(p_out, p_word);
    p_out[0]              = p_out[0] - 'a' + 'A';
    p_out[char_count - 1] = p_out[char_count - 1] - 'a' + 'A';
}

/**
 * @brief main
 * Entry point to the application
 *
 */
void main (int argc, char *argv[])
{
    uint8_t word_count = 0;
    uint8_t char_count = 0;
    char    out_str[100];
    uint8_t offset = 0;

    //
    // Clear output buffer
    //
    memset(out_str, '\0', sizeof(out_str));

    //
    // Argument counts gives the number of words entered
    //
    word_count = argc;

    //
    // Go through each words and check the first and last character is vowel or not
    // Skip application/project name from the argument(indexed 0)
    //
    for (uint8_t word = 1; word < word_count; word++) {
        //
        // Get the character count in the word
        //
        char_count = strlen(argv[word]);

        //
        // Check the first and last character for vowel
        //
        if (is_vowel(&argv[word][0], char_count)) {
            //
            // Change the first and last character case
            //
            caps_char(&argv[word][0], char_count, &out_str[offset]);
        } else {
            strcpy(&out_str[offset], argv[word]);
        }

        //
        // Insert space after each word
        //
        offset += char_count;
        out_str[offset++] = ' ';
    }

    //
    // Print result string
    //
    printf("%s", out_str);
}
