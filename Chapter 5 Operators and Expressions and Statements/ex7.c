/* C Primer Plus. Programming Exercise 5.7
 * Write a program that requests a type double number and prints the value of the number
 * cubed. Use a function of your own design to cube the value and print it. The main()
 * program should pass the entered value to this function.
 */
#include <stdio.h>
double cube(double val);

int main(void)
{
    double val;

    printf("Enter decimal value to power: ");
    scanf("%lf", &val);
    printf("%.2f^3 = %.2f\n", val, cube(val));

    return 0;
}

double cube(double val)
{
    return val * val * val;
}

