/**
 * @file arth_calculator.c
 * @author Jithin A
 * @brief Simple arithmetic calculator
 * @version 0.1
 * @date 2022-03-21
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char **argv)
{
    enum operator;
    float operand_1, operand_2;

    //
    // Get the operands from the console
    //
    operand_1 = atof(argv[2]);
    operand_2 = atof(argv[3]);

    //
    // Read the operator from the console and
    // perform the respective operation
    //
    if (strcmp(argv[1], "ADD")) {
        //
        // Perform addition
        //
        printf("Sum: %f", operand_1 + operand_2);
    }
    else if (argv[1], "SUB") {
        //
        // Perform subtraction
        //
        printf("Difference: %f", operand_1 - operand_2);
    }
    else if (argv[1], "MUL") {
        //
        // Perform multiplication
        //
        printf("Product: %f", operand_1 * operand_2);
    }
    else if (argv[1], "DIV") {
        //
        // Perform division
        //
        printf("Quotient: %f", operand_1 / operand_2);
    } else {
        //
        // Invalid operator
        //
        printf("Invalid operator\n");
    }
    return 0;
}
