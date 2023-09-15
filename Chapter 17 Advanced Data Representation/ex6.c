/* C Primer Plus. Programming Exercise 17.6
 * Write a function that takes three arguments: the name of an array of sorted integers, the
 * number of elements of the array, and an integer to seek. The function returns the value
 * 1 if the integer is in the array, and 0 if it isn’t. Have the function use the binary search
 * technique.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_in_array(const int sorted[], int n, int seek);
int compare_ints(const void* a, const void* b);

int main(void)
{

    int n;
    int i, seek;
    i = 0;

    printf("Enter the size of array:\n");
    scanf("%d", &n);
    while (getchar() != '\n')
        continue;
    if(n <= 0)
    {
        fprintf(stderr, "Error! Invalid array size!\n");
        exit(EXIT_FAILURE);
    }

    int numbers[n];
    printf("Enter %d integers to fill the array:\n", n);
    while (i < n && scanf("%d", &numbers[i]))
        i++;
    qsort(numbers, n, sizeof(int), compare_ints);
    printf("Enter a number to find in array:\n");
    scanf("%d", &seek);
    bool found = is_in_array(numbers, n, seek);
    if(found)
        printf("Integer %d was found!\n", seek);
    else
        printf("Integer %d was not found!\n", seek);

    return 0;
}

bool is_in_array(const int sorted[], int n, int seek)
{
    int left, pos, right;

    left = 0, right = n - 1;
    while (left < right)
    {
        pos = (left + right) / 2;
        if(sorted[pos] > seek)
            right = pos - 1;
        else if(sorted[pos] < seek)
            left = pos + 1;
        else
            return true;
    }

    return sorted[left] == seek;
}



int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
