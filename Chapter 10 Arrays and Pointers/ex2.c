/* C Primer Plus. Programming Exercise 10.2
 * Write a program that initializes an array-of-double and then copies the contents of the
 * array into three other arrays. (All four arrays should be declared in the main program.) To
 * make the first copy, use a function with array notation. To make the second copy, use a
 * function with pointer notation and pointer incrementing. Have the first two functions
 * take as arguments the name of the target array, the name of the source array, and the
 * number of elements to be copied. Have the third function take as arguments the name
 * of the target, the name of the source, and a pointer to the element following the last
 * element of the source. That is, the function calls would look like this, given the following
 * declarations:
 *  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
 *  double target1[5];
 *  double target2[5];
 *  double target3[5];
 *  copy_arr(target1, source, 5);
 *  copy_ptr(target2, source, 5);
 *  copy_ptrs(target3, source, source + 5);
 */
#include <stdio.h>
#define SIZE 5
void print_arr(double arr[], int size);
void copy_arr(double target[], const double source[], int size);
void copy_ptr(double target[], const double source[], int size);
void copy_ptrs(double* target, const double* source, const double* end);

int main(void)
{
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, SIZE);
    copy_ptr(target2, source, SIZE);
    copy_ptrs(target3, source, source + SIZE);

    print_arr(target1, SIZE);
    print_arr(target2, SIZE);
    print_arr(target3, SIZE);

    return 0;
}

void print_arr(double arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf("%.2lf, ", arr[i]);
    printf("\b\b");
    printf("]\n");
}

void copy_arr(double target[], const double source[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        target[i] = source[i];
}

void copy_ptr(double target[], const double source[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        *(target + i) = *(source + i);
}

void copy_ptrs(double* target, const double* source, const double* end)
{
    while (source <= end)
        *(target++) = *(source++);
}
