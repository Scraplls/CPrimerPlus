/* C Primer Plus. Programming Exercise 10.8
 * Use a copy function from Programming Exercise 2 to copy the third through fifth
 * elements of a seven-element array into a three-element array. The function itself need
 * not be altered; just choose the right actual arguments. (The actual arguments need not be
 * an array name and array size. They only have to be the address of an array element and a
 * number of elements to be processed.)
 */
#include <stdio.h>
void print_arr(double arr[], int size);
void copy_arr(double target[], const double source[], int size);

int main(void)
{
    double arr[7] = {0.1, -2.6, 1.1, 5, 0.2, 0.06, 0.001};
    double copy[3];

    printf("Original array: \n");
    print_arr(arr, 7);
    copy_arr(copy, arr+2, 3);
    printf("Copied array: \n");
    print_arr(copy, 3);
    return 0;
}

void copy_arr(double target[], const double source[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        target[i] = source[i];
}

void print_arr(double arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf("%.2lf, ", arr[i]);
    printf("\b\b");
    printf("]\n");
}