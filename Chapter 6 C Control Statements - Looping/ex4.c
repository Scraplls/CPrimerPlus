/* C Primer Plus. Programming Exercise 6.4
 * Use nested loops to produce the following pattern:
 * A
 * BC
 * DEF
 * GHIJ
 * KLMNO
 * PQRSTU
 * If your system doesn’t encode letters in numeric order, see the suggestion in
 * programming exercise 3.
 */
#include <stdio.h>

int main(void){
    int c = 0;

    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= i; j++)
            printf("%c", 'A' + c++);
        printf("\n");
    }

    return 0;
}
