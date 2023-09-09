/* C Primer Plus. Programming Exercise 11.1
 * Design and test a function that fetches the next n characters from input (including
 * blanks, tabs, and newlines), storing the results in an array whose address is passed as an
 * argument.
 */
#include <stdio.h>
#define SIZE 10
void fetchn(char* arr, int n);

int main(void)
{
    int i;
    char arr[SIZE + 1];

    fetchn(arr, SIZE);

    i = 0;
    while (i < SIZE)
        putchar(arr[i++]);
    putchar('\n');
    return 0;
}

void fetchn(char* arr, int n)
{
    int i;
    char ch;
    i = 0;
    while (i < n && (ch = getchar()) != EOF)
        arr[i++] = ch;
    arr[i] = '\0';
}