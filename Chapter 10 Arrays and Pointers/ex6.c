/* C Primer Plus. Programming Exercise 10.6
 * Write a function that reverses the contents of an array of double and test it in a simple
 * program.
 */
#include <stdio.h>
void print_arr(double arr[], int size);
void reverse_arr(double arr[], int size);

int main(void)
{
    double arr[4] = {1.2, 3.8, -0.4, -0.01};
    print_arr(arr, 4);
    reverse_arr(arr, 4);
    print_arr(arr, 4);
    return 0;
}

void print_arr(double arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf("%lf, ", arr[i]);
    printf("\b\b");
    printf("]\n");
}

void reverse_arr(double arr[], int size)
{
    int i;
    double tmp;

    for(i = 0; i < size/2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
}