/**
 * @file main.c
 * @author Jithin A
 * @brief Find the given number is perfect square or a cube
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdbool.h>
#include <string.h>
#include "../common.h"
#include "../root/root.h"

/**
 * @brief print_help
 * Brief input parameter
 *
 */
void print_help (void)
{
    printf(PRED"Invalid input\n"PNRM);
    printf("Ex: "PGRN"<Number> <square/cube>\n"PNRM);
    printf("-- Square: check the number is perfect square or not\n");
    printf("-- Cube  : check the number is perfect cube or not\n");
}

/**
 * @brief main
 * Entry point to the program
 *
 * @param argc - argument count
 * @param argv - argument vector
 */
void main (int argc, char *argv[])
{
    uint32_t num     = 0;
    uint8_t  root    = 0;
    bool     is_root = false;

    //
    // Validate we have input to process
    //
    if (argc != 3) {
        print_help();
        return;
    }

    //
    // Get the input
    //
    num  = atoi(argv[1]);
    if (strcmp(argv[2], "square") == 0) {
        root = SQ_ROOT;
    }
    else if (strcmp(argv[2], "cube") == 0) {
        root = CUBE_ROOT;
    }
    else {
        //
        // Invalid input print help
        //
        print_help();
        return;
    }

    //
    // Check if the number is square/cube root
    //
    if(is_perfect_root(num, root)) {
        if (root == SQ_ROOT) {
            printf(PGRN"The number is perfect square\n"PNRM);
        } else {
            printf(PGRN"The number is perfect cube\n"PNRM);
        }
    } else {
        printf(PRED"The number is not a perfect square or cube\n"PNRM);
    }
}
