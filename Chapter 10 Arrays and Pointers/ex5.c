/* C Primer Plus. Programming Exercise 10.5
 * Write a function that returns the difference between the largest and smallest elements of
 * an array-of-double. Test the function in a simple program.
 */
#include <stdio.h>
void print_arr(double arr[], int size);
double diff(double arr[], int size);

int main(void)
{
    double arr[5] = {1.5, 1.3, 2.4, -0.01, 2.1};
    printf("arr: ");
    print_arr(arr, 5);
    printf("Difference between the largest and smallest values of array is %lf\n", diff(arr, 5));
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

double diff(double arr[], int size)
{
    if(size < 2)
        return 0;
    double smallest, largest;
    int i;
    smallest = arr[0] < arr[1] ? arr[0] : arr[1];
    largest = arr[0] > arr[1] ? arr[0] : arr[1];
    for(i = 0; i < size; i++)
    {
        if(arr[i] > largest)
            largest = arr[i];
        else if(arr[i] < smallest)
            smallest = arr[i];
    }
    return largest - smallest;
}