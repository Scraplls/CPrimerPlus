/* C Primer Plus. Programming Exercise 7.1
 * Write a program that reads input until encountering the # character and then reports
 * the number of spaces read, the number of newline characters read, and the number of all
 * other characters read.
 */
#include <stdio.h>

int main(void){
    char ch;
    int spaces, newlines, other;

    spaces = newlines = other = 0;
    while ((ch = getchar()) != '#'){
        if (ch == ' ')
            spaces++;
        else if (ch == '\n')
            newlines++;
        else
            other++;
    }

    printf("Spaces count: %d, newlines count: %d, other characters count: %d\n",
           spaces, newlines, other);

    return 0;
}