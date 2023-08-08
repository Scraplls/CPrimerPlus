/* C Primer Plus. Programming Exercise 10.11
 * Write a program that declares a 3×5 array of int and initializes it to some values of
 * your choice. Have the program print the values, double all the values, and then display
 * the new values. Write a function to do the displaying and a second function to do the
 * doubling. Have the functions take the array name and the number of rows as arguments.
 */
#include <stdio.h>
void doubl(int arr[][5], int rows);
void printarr(int arr[][5], int rows);

int main(void)
{
    int arr[3][5] = {{1, 0, 1, 2, 3},
                     {0, 0, 1, 2, 1},
                     {2, 2, 3, 4, 5}};
    printarr(arr, 3);
    printf("\n");
    doubl(arr, 3);
    printarr(arr, 3);
    return 0;
}

void doubl(int arr[][5], int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
        for(j = 0; j < 5; j++)
            arr[i][j] *= 2;
}

void printarr(int arr[][5], int rows)
{
    int i, j;
    for(i = 0; i < rows; i++){
        printf("[");
        for(j = 0; j < 5; j++)
            printf("%d, ", arr[i][j]);
        printf("\b\b]\n");
    }
}
