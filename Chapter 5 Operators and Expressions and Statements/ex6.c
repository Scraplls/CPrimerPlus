/* C Primer Plus. Programming Exercise 5.6
 * Now modify the program of Programming Exercise 5 so that it computes the sum of the
 * squares of the integers. (If you prefer, how much money you receive if you get $1 the
 * first day, $4 the second day, $9 the third day, and so on. This looks like a much better
 * deal!) C doesn’t have a squaring function, but you can use the fact that the square of n is
 * n * n.
 */
#include <stdio.h>

int main(void)
{
    int count, end;

    count = 0;
    printf("Enter the counter end: ");
    scanf("%d", &end);
    while (count++ < end)
        printf("%d * %d = %d\n", count, count, count * count);

    return 0;
}