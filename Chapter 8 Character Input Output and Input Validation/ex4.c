/* C Primer Plus. Programming Exercise 8.4
 * Write a program that reads input as a stream of characters until encountering EOF. Have
 * it reported the average number of letters per word. Don’t count whitespace as being letters
 * in a word. Actually, punctuation shouldn’t be counted either, but don’t worry about that
 * now. (If you do want to worry about it, consider using the ispunct() function from the
 * ctype.h family.)
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int words, letters, average;

    words = letters = average = 0;
    while ((ch = getchar()) != EOF){
        if (ch == ' ')
            words++;
        else if (!ispunct(ch))
            letters++;
    }
    average = letters / words;

    printf("Average number of letters per word: %d\n", average);

    return 0;
}