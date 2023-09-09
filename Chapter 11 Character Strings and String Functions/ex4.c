/* C Primer Plus. Programming Exercise 11.4
 * Design and test a function like that described in Programming Exercise 3 except that it
 * accepts a second parameter specifying the maximum number of characters that can be
 * read.
 */
#include <stdio.h>
#include <ctype.h>
#define SIZE 50

void readnword(char* arr, int n);

int main(void)
{
    char word[SIZE];

    printf("Enter some characters:\n");
    readnword(word, 5);
    printf("%s\n", word);
    return 0;
}

void readnword(char* arr, int n)
{
    char ch;
    int i;
    i = 0;

    while (isspace(ch = getchar()))
        continue;

    do
        *(arr+i) = ch;
    while (++i < n && !isspace(ch = getchar()));
    *(arr+i) = '\0';
}