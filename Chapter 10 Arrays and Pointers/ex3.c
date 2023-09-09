/* C Primer Plus. Programming Exercise 10.3
 * Write a function that returns the largest value stored in an array-of-int. Test the function
 * in a simple program.
 */
#include <stdio.h>
void print_arr(int arr[], int size);
int largest(int [], int);

int main(void)
{
    int arr[5] = {10, -1, 0, 60, 34};
    printf("arr: ");
    print_arr(arr, 5);
    printf("Largest value - %d\n", largest(arr, 5));
    return 0;
}

void print_arr(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("\b\b");
    printf("]\n");
}

int largest(int arr[], int size)
{
    int largest, i;
    largest = arr[0];
    for(i = 1; i < size; i++)
    {
        if(arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}