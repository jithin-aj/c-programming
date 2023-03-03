#include <stdio.h>
#include <stdint.h>

int main ()
{
    uint32_t *p_addr = (uint32_t *)0x1000;
    uint32_t addr = 0;

    addr = (uint32_t)p_addr + (8 * 1024);
    printf("0x%02X", addr);

    return 0;
}