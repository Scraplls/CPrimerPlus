/* C Primer Plus. Programming Exercise 15.1
 * Write a function that converts a binary string to a numeric value. That is, if you have
 * char * pbin = "01001001";
 * you can pass pbin as an argument to the function and have the function return an int
 * value of 73.
 */
#include <stdio.h>

int btoi(const char* binary);

int main(void)
{
    char *pbin = "01001001";
    printf("%s = %d (int base 10)\n", pbin, btoi(pbin));
    return 0;
}

int btoi(const char* binary)
{
    int i;
    int n = 0;
    i = 0;

    while(binary[i] != '\0')
    {
        n <<= 1;
        n |= (binary[i] - '0') & 0x1;
        i++;
    }
    return n;
}