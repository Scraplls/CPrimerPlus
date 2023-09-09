/* C Primer Plus. Programming Exercise 7.2
 * Write a program that reads input until encountering #. Have the program print each
 * input character and its ASCII decimal code. Print eight character-code pairs per line.
 * Suggestion: Use a character count and the modulus operator (%) to print a newline
 * character for every eight cycles of the loop.
 */
#include <stdio.h>

int main(void){
    char ch;
    int i;

    i = 0;
    while ((ch = getchar()) != '#'){
        if(ch == '\n')
            continue;
        i++;
        printf("%c - %3d", ch, ch);
        if (i % 8 == 0)
            putchar('\n');
    }

    return 0;
}