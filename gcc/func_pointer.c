#include <stdio.h>
#include <stdlib.h>

void add (int a, int b)
{
    printf("Sum: %d", (a + b));
}

void sub (int a, int b)
{
    printf("Sub: %d", (a - b));
}

void mul (int a, int b)
{
    printf("Mul: %d", (a * b));
}

void divs (int a, int b)
{
    printf("Div: %d", (a / b));
}

void divsi (int a, int b)
{
    printf("Div: %d", (a / b));
}

void (*ble_comm_proc[])(int a, int b) = {
    add,
    sub,
    mul,
    divs,
    divsi
};

int main(int argc, char **argv)
{
    int oper;
    int a = 20, b = 10;

    //
    // Get operator
    //
    oper = atoi(argv[1]);
    if (oper > 3) return 0;

    //
    // Perform operation using func pointer
    //
    (*ble_comm_proc[oper])(a, b);

    //
    // Print the size of function pointer array
    //
    printf("\nSize: %ld", sizeof(ble_comm_proc));
    return 0;
}
