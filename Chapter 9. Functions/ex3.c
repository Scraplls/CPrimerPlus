/* C Primer Plus. Programming Exercise 9.3
 * Write a function that takes three arguments: a character and two integers. The character
 * is to be printed. The first integer specifies the number of times that the character is to
 * be printed on a line, and the second integer specifies the number of lines that are to be
 * printed. Write a program that makes use of this function.
 */
#include <stdio.h>
void chrect(char ch, int rows, int cols);

int main(void){
    int rows, cols;
    rows = 5;
    cols = 5;
    chrect('*', rows, cols);
    return 0;
}

void chrect(char ch, int rows, int cols){
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            putchar(ch);
        }
        putchar('\n');
    }
}