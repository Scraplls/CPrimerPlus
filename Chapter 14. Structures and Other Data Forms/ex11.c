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
double inverse(double x);
double fibb(double x);

int main(void)
{
    char choice;
    int filled;

    double source[100];
    double target[100];

    printf("Source array address: %p\n", source);
    printf("Target array address: %p\n", target);
    printf("===Transformation program===\n"
           "To choose a function, enter its letter label:\n"
           "a) random fill an array\n"
           "b) transform an array\n"
           "c) show source array\n"
           "q) quit\n");
    while ((choice = getchar()) != 'q' && choice != EOF)
    {
        while (getchar() != '\n')
            continue;
        switch (choice) {
            case 'a':
                fillarr(source, 100);
                filled = 1;
                showarr(source, 100);
                break;
            case 'b':
                if(!filled)
                {
                    printf("Transformation failed! Array is empty!\n");
                    break;
                }
                printf("Select a function to transform the array: \n"
                       "a) sin  b) log\n"
                       "c) inverse  d) fibb\n");
                choice = getchar();
                while (getchar() != '\n')
                    continue;
                switch (choice) {
                    case 'a':
                        transform(source, target, 100, sin);
                        showarr(target, 100);
                        break;
                    case 'b':
                        transform(source, target, 100, log);
                        showarr(target, 100);
                        break;
                    case 'c':
                        transform(source, target, 100, inverse);
                        showarr(target, 100);
                        break;
                    case 'd':
                        transform(source, target, 100, fibb);
                        showarr(target, 100);
                        break;
                    default:
                        break;
                }
                break;
            case 'c':
                showarr(source, 100);
                break;
            default:
                printf("Selected function was not found! Try again!\n");
                break;
        }
        printf("===Transformation program===\n"
               "To choose a function, enter its letter label:\n"
               "a) random fill an array\n"
               "b) transform an array\n"
               "c) show source array\n"
               "q) quit\n");
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
    while (getchar() != '\n')
        continue;
    srand(seed);
    for(int i = 0; i < n; i++)
        arr[i] = (rand() % 10) + (rand() % 10) * 1.0 / (rand() % 10 + 1);
}

void showarr(double arr[], int n)
{
    int i;
    printf("Array %p: \n", arr);
    for (i = 0; i < n; ++i)
    {
        printf("%.2f ", arr[i]);
        if(i % 10 == 9)
            printf("\n");
    }
    if(i % 10 == 9)
        printf("\n");
}

double inverse(double x)
{
    return 1.0 / x;
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

void transform(const double source[], double target[], int n, double (*fp)(double))
{
    for (int i = 0; i < n; ++i)
        target[i] = fp(source[i]);
}