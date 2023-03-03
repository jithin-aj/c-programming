#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct {
    uint16_t aid_list;
    char issuer_name[16];
    char card_holder_name[16];
    char nick_name[7];
    char full_pan[16];
    char scheme_name[20];
    uint8_t logo_id;
    uint8_t card_other;
    uint8_t pending;
    uint8_t cvv;
    uint8_t exp_date;
    uint16_t exp_year;
    uint16_t pan_4_digit;
}card_struct;

int main (void)
{
    struct card_struct;
    printf("%d", sizeof(card_struct));
}