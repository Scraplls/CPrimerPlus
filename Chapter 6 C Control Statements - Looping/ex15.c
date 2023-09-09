/* C Primer Plus. Programming Exercise 6.15
 * Write a program that reads in a line of input and then prints the line in reverse order.
 * You can store the input in an array of char; assume that the line is no longer than 255
 * characters. Recall that you can use scanf() with the %c specifier to read a character at
 * a time from input and that the newline character (\n) is generated when you press the
 * Enter key.
 */
#include <stdio.h>
#define MAX_LINE_LENGTH 255

int main(void){
    char input[MAX_LINE_LENGTH];
    char ch;
    int i;

    scanf("%c", &ch);
    i = 0;
    while(ch != '\n' && i < MAX_LINE_LENGTH - 1){
        input[i] = ch;
        i++;
        scanf("%c", &ch);
    }
    input[i] = '\0';
    while (--i >= 0)
        printf("%c", input[i]);

    return 0;
}