/* C Primer Plus. Programming Exercise 10.7
 * Write a program that initializes a two-dimensional array-of-double and uses one of the
 * copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a
 * two-dimensional array is an array of arrays, a one-dimensional copy function can be used
 * with each subarray.)
 */
#include <stdio.h>
#define COLS_SIZE 3

void copy_arr(double target[], const double source[], int size);
void copy_arr2d(double target[][COLS_SIZE], const double source[][COLS_SIZE], int rows, int cols);
void print_arr(double arr[][COLS_SIZE], int rows, int cols);

int main(void)
{
    double arr[2][COLS_SIZE] = {{1.0, 3.0, 0.0}, {2.0, 4.0, 5.0}};
    double copy[2][COLS_SIZE];
    printf("Original array: \n");
    print_arr(arr, 2, COLS_SIZE);
    copy_arr2d(copy, arr, 2, COLS_SIZE);
    printf("Copied array: \n");
    print_arr(copy, 2, COLS_SIZE);
    return 0;
}

void copy_arr2d(double target[][COLS_SIZE], const double source[][COLS_SIZE], int rows, int cols)
{
    int i;
    for(i = 0; i < rows; i++)
        copy_arr(target[i], source[i], cols);
}

void copy_arr(double target[], const double source[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        target[i] = source[i];
}

void print_arr(double arr[][COLS_SIZE], int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        printf("[");
        for (j = 0; j < cols; j++)
            printf("%lf, ", arr[i][j]);
        printf("\b\b");
        printf("]\n");
    }
}