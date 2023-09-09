/* C Primer Plus. Programming Exercise 14.10
 * Write a program that implements a menu by using an array of pointers to functions. For
 * instance, choosing a from the menu would activate the function pointed to by the first
 * element of the array.
 */
#include <stdio.h>
#include <math.h>

#define MAXFUNC 5

typedef double (*CALC_FP) (double a, double b);
double sum(double a, double b);
double diff(double a, double b);
double mult(double a, double b);
double div(double a, double b);
double avg(double a, double b);


int main(void)
{
    CALC_FP functions[MAXFUNC] = {sum, diff, mult, div, avg};

    double a, b;
    int ch;

    puts("Choose an operation:");
    puts("a) addition");
    puts("b) difference");
    puts("c) multiplication");
    puts("d) division");
    puts("e) average");
    puts("f) quit");

    while ((ch = getchar()) != 'f')
    {
        while (getchar() != '\n')
            continue;
        ch = ch - 'a';
        if (ch < 0 || ch > 4)
        {
            puts("This is not a valid option. Try again.");
            continue;
        }
        printf("Enter two numbers: ");
        while(scanf("%lf %lf", &a, &b) != 2)
        {
            while (getchar() != '\n')
                continue;
            printf("Invalid input. Enter two numbers: ");
        }

        while (getchar() != '\n')
            continue;
        printf("%f\n", functions[ch](a, b));
        puts("");
        puts("Choose an operation:");
        puts("a) addition");
        puts("b) difference");
        puts("c) multiplication");
        puts("d) division");
        puts("e) average");
        puts("f) quit");
    }
    puts("Bye.");
}

double sum(double a, double b)
{
    return a + b;
}

double diff(double a, double b)
{
    return fabs(a - b);
}

double mult(double a, double b)
{
    return a * b;
}

double div(double a, double b)
{
    return a / b;
}

double avg(double a, double b)
{
    return (a + b) / 2;
}