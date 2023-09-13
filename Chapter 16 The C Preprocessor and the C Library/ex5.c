/* C Primer Plus. Programming Exercise 16.5
 * Write a function that takes as arguments the name of an array of type int elements, the
 * size of an array, and a value representing the number of picks. The function then should
 * select the indicated number of items at random from the array and prints them. No
 * array element is to be picked more than once. (This simulates picking lottery numbers or
 * jury members.) Also, if your implementation has time() (discussed in Chapter 12) or a
 * similar function available, use its output with srand() to initialize the rand() random-
 * number generator. Write a simple program that tests the function.
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ex1.h"

void printarr(int arr[], int n);
void randpick(int arr[], int n, int picks);
bool ispicked(int arr[], int n);

static bool* picked;

int main(void)
{
    int i, n, picks;
    int* array;
    picks = 0;
    n = 0;

    printf("Enter the size of an array:\n");
    scanf("%d", &n);
    CLEARINPUT;
    if(n <= 0)
    {
        fprintf(stderr, "Error! Size of an array must be greater than 0.");
        exit(EXIT_FAILURE);
    }
    array = (int*) malloc(n * sizeof(int));
    picked = (bool*) malloc(n * sizeof(bool));
    for(i = 0; i < n; i++)
    {
        picked[i] = false;
        array[i] = 0;
    }
    printf("Enter the contents of an array (e.g. 1 2 3 4 ...):\n");
    i = 0;
    while (i < n && scanf("%d", &array[i]))
        i++;
    CLEARINPUT;

    printarr(array, n);
    printf("Enter the number of picks:\n");
    while(scanf("%d", &picks) && picks != 0)
    {
        CLEARINPUT;
        randpick(array, n, picks);
        printarr(array, n);
        if(ispicked(array, n))
        {
            printf("There are no elements in the array to be picked!\n");
            break;
        }
        printf("Enter the number of picks:\n");
    }
    printf("Bye!\n");
    return 0;
}

void printarr(int arr[], int n)
{
    printf("Current array: ");
    for(int i = 0; i < n; i++)
        printf("%c%c", picked[i] ? '_' : ' ', ' ');
    printf("\n               ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void randpick(int arr[], int n, int picks)
{
    int pos, i;
    srand(clock());

    printf("Picked numbers: ");
    for(i = 0; i < picks && !ispicked(arr, n);)
    {
        pos = rand() % n;
        if(!picked[pos])
        {
            picked[pos] = true;
            printf("%d, ", arr[pos]);
            i++;
        }
    }
    printf("count=%d\n", i);
}

bool ispicked(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        if(!picked[i])
            return false;
    return true;
}