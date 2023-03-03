/**
 * @file main.c
 * @author Jithin A
 * @brief Run a simple calculator program using CMAKE multi files environment
 * @version 0.1
 * @date 2022-12-07
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "common.h"
#include "simple_calculator.h"

/**
 * @brief main
 * Entry point to the application
 *
 * @param argc - argument count
 * @param argv - argument vector
 */
void main (int argc, char *argv[])
{
    int      oper_1 = 0;
    int      oper_2 = 0;
    char     opr    = 0;
    long int result = 0;

    //
    // Validate we have input to process
    //
    if (argc != 4) {
        printf(PRED"Invalid input\n"PNRM);
        printf("Ex: "PGRN"<operand_1> <operator> <operand_2>\n"PNRM);
        return;
    }

    //
    // Get the inputs
    //
    oper_1 = atoi(argv[1]);
    opr    = *argv[2];
    oper_2 = atoi(argv[3]);

    //
    // Perform the requested operation
    //
    result = calculator(oper_1, oper_2, opr);
    printf(PRED"%d "PGRN"%c "PRED"%d "PNRM"= " PRED"%ld \n"PNRM, oper_1, opr, oper_2, result);
}