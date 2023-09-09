/* C Primer Plus. Programming Exercise 10.4
 * Write a function that returns the index of the largest value stored in an array-of-double.
 * Test the function in a simple program.
 */
#include <stdio.h>
void print_arr(double arr[], int size);
double largest(double [], int);

int main(void)
{
    double arr[5] = {1.5, 1.3, 2.4, -0.01, 2.1};
    printf("arr: ");
    print_arr(arr, 5);
    printf("Largest value - %lf\n", largest(arr, 5));
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

double largest(double arr[], int size)
{
    double largest;
    int i;
    largest = arr[0];
    for(i = 1; i < size; i++)
    {
        if(arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}