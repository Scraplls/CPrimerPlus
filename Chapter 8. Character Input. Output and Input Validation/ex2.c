/* C Primer Plus. Programming Exercise 8.2
 * Write a program that reads input as a stream of characters until encountering EOF. Have
 * the program print each input character and its ASCII decimal value. Note that characters
 * preceding the space character in the ASCII sequence are nonprinting characters.
 * Treat them specially. If the nonprinting character is a newline or tab, print \n or \t,
 * respectively. Otherwise, use control-character notation. For instance, ASCII 1 is Ctrl+A,
 * which can be displayed as ^A. Note that the ASCII value for A is the value for Ctrl+A
 * plus 64. A similar relation holds for the other nonprinting characters. Print 10 pairs per
 * line, except start a fresh line each time a newline character is encountered. (Note: The
 * operating system may have special interpretations for some control characters and keep
 * them from reaching the program.)
 */
#include <stdio.h>

int main(void)
{
    char ch;
    int count;

    count = 0;
    while ((ch = getchar()) != EOF)
    {
        count++;
        if (ch >= ' ')
            printf("%c ", ch);
        else if (ch == '\n' || ch == '\t')
            printf("%s", ch == '\n' ? "\\n" : "\\t");
        else
            printf("^%c", ch + 64);
        printf("%-5d", ch);
        if (ch == '\n')
            count = 0;
        if (count % 10 == 0)
            printf("\n");
    }

    return 0;
}