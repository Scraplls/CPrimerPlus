/* C Primer Plus. Programming Exercise 7.4
 * Using if else statements, write a program that reads input up to #, replaces each period
 * with an exclamation mark, replaces each exclamation mark initially present with two
 * exclamation marks, and reports at the end the number of substitutions it has made.
 */
#include <stdio.h>

int main(void){
    char ch;
    int replaces;

    replaces = 0;
    while ((ch = getchar()) != '#'){
        if (ch == '.'){
            putchar('!');
            replaces++;
        } else if (ch == '!'){
            putchar('!');
            putchar('!');
            replaces++;
        } else {
            putchar(ch);
        }
    }
    printf("\nTotal substitutions: %d\n", replaces);

    return 0;
}
