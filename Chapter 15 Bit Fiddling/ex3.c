/* C Primer Plus. Programming Exercise 15.3
 * Write a function that takes an int argument and returns the number of “on” bits in the
 * argument. Test the function in a program.
 */
#include <stdio.h>
#include <limits.h>

int getbitson(int n);

int main(void)
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Total number of 'on' bits: %d\n", getbitson(n));
    return 0;
}

int getbitson(int n)
{
    int count;
    int i;
    static const int size = sizeof(int) * CHAR_BIT;
    count = 0;
    for (i = 0; i < size; i++, n >>= 1)
        count += (n & 0x1);

    return count;
}