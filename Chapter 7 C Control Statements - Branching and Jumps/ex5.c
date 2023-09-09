/* C Primer Plus. Programming Exercise 7.5
 * Redo exercise 4 using a switch
 */
#include <stdio.h>

int main(void){
    char ch;
    int replaces;

    replaces = 0;
    while ((ch = getchar()) != '#'){
        switch (ch){
            case '.':
                putchar('!');
                replaces++;
                break;
            case '!':
                putchar('!');
                putchar('!');
                replaces++;
                break;
            default:
                putchar(ch);
        }
    }
    printf("\nTotal substitutions: %d\n", replaces);

    return 0;
}
