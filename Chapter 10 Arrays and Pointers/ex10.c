/* C Primer Plus. Programming Exercise 10.10
 * Write a function that sets each element in an array to the sum of the corresponding
 * elements in two other arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2
 * has the values 1, 0, 4 , and 6, the function assigns array 3 the values 3 , 4, 9, and 14. The
 * function should take three array names and an array size as arguments. Test the function
 * in a simple program.
 */
#include <stdio.h>
#define SIZE 4

void printarr(const int arr[], int size);
void sumarrs(const int a1[], const int a2[], int sum[], int size);

int main(void)
{
    int a1[SIZE] = {2, 4, 5, 8};
    int a2[SIZE] = {1, 0, 4, 6};
    int sum[SIZE];
    printf("a1: ");
    printarr(a1, SIZE);
    printf("a2: ");
    printarr(a2, SIZE);
    sumarrs(a1, a2, sum, SIZE);
    printf("a1 + a2 (by elements): ");
    printarr(sum, SIZE);
    return 0;
}

void printarr(const int arr[], int size)
{
    int i;
    printf("[");
    for(i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\b\b]\n");
}

void sumarrs(const int a1[], const int a2[], int sum[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        sum[i] = a1[i] + a2[i];
}