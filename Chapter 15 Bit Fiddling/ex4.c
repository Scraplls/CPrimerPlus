/* C Primer Plus. Programming Exercise 15.4
 * Write a function that takes two int arguments: a value and a bit position. Have the
 * function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test
 * the function in a program.
 */
#include <stdio.h>

int bitat(int val, int pos);

int main(void)
{
    int val = -87;
    int pos = 31;
    int bit = bitat(val, pos);
    printf("int %d has %d at bit position %d\n", val, bit, pos);

    return 0;
}

int bitat(int val, int pos)
{
    return (val >> pos) & 0x1;
}