/* C Primer Plus. Programming Exercise 16.2
 * The harmonic mean of two numbers is obtained by taking the inverses of the two
 * numbers, averaging them, and taking the inverse of the result. Use a #define directive
 * to define a macro “function” that performs this operation. Write a simple program that
 * tests the macro.
 */
#include <stdio.h>

#define harmonic(x, y) (2/(1/x + 1/y))

int main(void)
{
    double x, y;
    printf("Enter values of x and y:\n");
    scanf("%lf%lf", &x, &y);
    printf("harmonic(x, y)=%.2lf\n", harmonic(x, y));

    return 0;
}
