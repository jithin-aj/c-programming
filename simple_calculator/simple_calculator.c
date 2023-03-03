/**
 * @file simple_calculator.c
 * @author Jithin A
 * @brief Simple calculator application
 * @version 0.1
 * @date 2022-12-07
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes */
#include "simple_calculator.h"

/**
 * @brief calculator
 * Function perform a simple calculator operation based on the requested operation
 *
 * @param op1 - operand 1
 * @param op2 - operand 2
 * @param opr - operation to perform
 * @return long int
 */
long int calculator (int op1, int op2, char opr)
{
    long int res = 0;

    //
    // Perform the operation w.r.t requested operator
    //
    switch (opr)
    {
    case ADD:
    {
        res = op1 + op2;
    }
    break;

    case SUB:
    {
        res = op1 - op2;
    }
    break;

    case MUL:
    {
        res = op1 * op2;
    }
    break;

    case DIV:
    {
        res = op1 / op2;
    }
    break;

    case MOD:
    {
        res = op1 % op2;
    }
    break;

    default:
    {
        //
        // Unkown operation, do nothing
        //
    }
    break;
    }

    return res;
}