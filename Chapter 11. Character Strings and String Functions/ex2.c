/* C Primer Plus. Programming Exercise 11.2
 * Modify and test the function in exercise 1 so that it stops after n characters or after the
 * first blank, tab, or newline, whichever comes first. (Don’t just use scanf().)
 */
#include <stdio.h>
#define SIZE 10
void fetchn(char* arr, int n);

int main(void)
{
    int i;
    char arr[SIZE];

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
    while (i < n && (ch = getchar()) != EOF && ch != ' ' && ch != '\t' && ch != '\n')
        arr[i++] = ch;
}