/* C Primer Plus. Programming Exercise 11.3
 * Design and test a function that reads the first word from a line of input into an array and
 * discards the rest of the line. It should skip over leading whitespace. Define a word as a
 * sequence of characters with no blanks, tabs, or newlines in it. Use getchar().
 */
#include <stdio.h>
#include <ctype.h>
#define SIZE 50

void readword(char* arr);

int main(void)
{
    char word[SIZE];

    printf("Enter some characters:\n");
    readword(word);
    printf("%s\n", word);
    return 0;
}

void readword(char* arr)
{
    char ch;

    while (isspace(ch = getchar()))
        continue;

    do
        *arr++ = ch;
    while (!isspace(ch = getchar()));
    *arr = '\0';
}