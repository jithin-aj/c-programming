#include <stdio.h>
#include <stdlib.h>

int (*p_fun)(int, int);
int add(int oper_1, int oper_2);

int add (int oper_1, int oper_2)
{
    printf("Sum: %d", oper_1 + oper_2);
}

int main (int argc, char **argv)
{
    int oper_1, oper_2;

    oper_1 = atoi(argv[1]);
    oper_2 = atoi(argv[2]);
    p_fun = add;
    p_fun(oper_1, oper_2);

    return 0;
}