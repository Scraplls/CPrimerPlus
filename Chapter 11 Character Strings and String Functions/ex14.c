/* C Primer Plus. Programming Exercise 11.14
 * Write a power-law program that works on a command-line basis. The first command-line
 * argument should be the type double number to be raised to a certain power, and the
 * second argument should be the integer power.
 */
#include <stdio.h>
#include <stdlib.h>

double power(double base, int power);

int main(int argc, char* argv[])
{
    double num, res;
    int pow;

    num = atof(argv[1]);
    pow = atoi(argv[2]);

    res = power(num, pow);
    printf("%.2lf times %d is %.2lf\n", num, pow, res);
    return 0;
}

double power(double base, int power)
{
    double num;

    num = 1;
    while (power > 0)
    {
        if (power % 2 == 0)
        {
            power /= 2;
            base = base * base;
        }
        else
        {
            power -= 1;
            num = num * base;

            power /= 2;
            base = base * base;
        }
    }

    return num;
}
