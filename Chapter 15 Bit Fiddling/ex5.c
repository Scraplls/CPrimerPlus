/* C Primer Plus. Programming Exercise 15.5
 * Write a function that rotates the bits of an unsigned int by a specified number of bits
 * to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left,
 * and the bits lost from the left end would reappear at the right end. That is, the bit moved
 * out of the high-order position is placed in the low-order position. Test the function in a
 * program.
 */
#include <stdio.h>
#include <limits.h>
const static int UINT_SIZE = CHAR_BIT * sizeof(unsigned int);

char * itobs(unsigned int n, char * ps);
unsigned int rotate_l(unsigned int val, int n);

int main(void)
{
    unsigned int x;
    int n;
    char binstr[UINT_SIZE + 1];

    printf("Enter an unsigned integer x: \n");
    scanf("%ud", &x);
    itobs(x, binstr);
    printf("x = %d = %s (binary)\n", x, binstr);
    printf("Enter the n of bits to rotate: \n");
    scanf("%d", &n);

    x = rotate_l(x, n);
    itobs(x, binstr);
    printf("x = %d = %s (binary)\n", x, binstr);
    return 0;
}

unsigned int rotate_l(unsigned int val, int n)
{
    return val << n | (val >> (UINT_SIZE - n));
}

char * itobs(unsigned int n, char * ps)
{
    int i;
    for (i = UINT_SIZE - 1; i >= 0; i--, n >>= 1)
        ps[i] = (n & 0x1) + '0';
    ps[UINT_SIZE] = '\0';
    return ps;
}