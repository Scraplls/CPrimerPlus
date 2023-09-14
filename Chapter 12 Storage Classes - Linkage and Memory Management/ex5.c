/* C Primer Plus. Programming Exercise 12.5
 * Write a program that generates a list of 100 random numbers in the range 1–10
 * in sorted decreasing order. (You can adapt the sorting algorithm from Chapter 11
 * to type int. In this case, just sort the numbers themselves.)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void sortarr(int arr[], int n);

int main(void)
{
    int numbers[SIZE];
    int i;
    srand((unsigned int) time(0));
    i = 0;
    while (i < SIZE)
        numbers[i++] = rand() % 10 + 1;

    i = 0;
    printf("Array of random integers: \n");
    while (i < SIZE)
    {
        printf("%-4d ", numbers[i]);
        if(i % 10 == 9)
            printf("\n");
        i++;
    }

    sortarr(numbers, SIZE);

    i = 0;
    printf("\nSorted array of random integers: \n");
    while (i < SIZE)
    {
        printf("%-4d ", numbers[i]);
        if(i % 10 == 9)
            printf("\n");
        i++;
    }
    if(i % 10 != 0)
        printf("\n");
    return 0;
}

void sortarr(int arr[], int n)
{
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
}