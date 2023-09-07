/* C Primer Plus. Programming Exercise 14.11
 * Write a function called transform() that takes four arguments: the name of a source
 * array containing type double data, the name of a target array of type double, an int
 * representing the number of array elements, and the name of a function (or, equivalently,
 * a pointer to a function). The transform() function should apply the indicated function
 * to each element in the source array, placing the return value in the target array. For
 * example, the call
 *
 * transform(source, target, 100, sin);
 *
 * would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function
 * in a program that calls transform() four times, using two functions from the math.h
 * library and two suitable functions of your own devising as arguments to successive calls
 * of the transform() function.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void fillarr(double arr[], int n);
void showarr(double arr[], int n);
void transform(const double source[], double target[], int n, double (*fp)(double));
double rem(double x);
double fibb(double x);

int main(void)
{
    int choice;
    int filled;

    double source[100];
    double target[100];

    printf("===Transformation program===\n"
           "To choose a function, enter its letter label:\n"
           "a) random fill an array\n"
           "b) transform an array\n"
           "q) quit\n");
    while ((choice = getchar()) != 'q' && choice != EOF)
    {
        switch (choice) {
            case 'a':
                fillarr(source, 100);
                printf("Source array: ");
                showarr(source, 100);
                printf("\n");
                break;
            case 'b':
                printf("Select a function to perform array transformation: "
                       "a) sin  b) cos\n"
                       "c) ");
        }
    }
    return 0;
}

void fillarr(double arr[], int n)
{
    unsigned int seed;
    int read;
    printf("Enter a seed number: ");
    while ((read = scanf("%u", &seed)) != 1 && read != EOF)
        printf("Invalid input!\nRe-enter a seed number: ");
    srand(seed);
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 10 + rand() % 10 / rand() % 10;
}

void showarr(double arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; ++i)
        printf("%.2f, ", arr[i]);
    printf("\b\b]");
}

double rem(double x)
{
    return x - (int) x;
}

double fibb(double x)
{
    int i;
    double f, f0, tmp;
    if((int) x < 1)
        return 0;
    f = 1;
    f0 = 0;
    for(i = 1; i < (int) x; i++)
    {
        tmp = f;
        f = f + f0;
        f0 = tmp;
    }

    return f;
}