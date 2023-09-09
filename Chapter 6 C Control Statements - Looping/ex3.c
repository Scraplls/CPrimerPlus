/* C Primer Plus. Programming Exercise 6.3
 * Use nested loops to produce the following pattern:
 * F
 * FE
 * FED
 * FEDC
 * FEDCB
 * FEDCBA
 * Note: If your system doesn’t use ASCII or some other code that encodes letters in
 * numeric order, you can use the following to initialize a character array to the letters of
 * the alphabet:
 * char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 * Then you can use the array index to select individual letters; for example, lets[0] is
 * 'A', and so on.
 */
#include <stdio.h>

int main(void){

    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= i; j++){
            printf("%c", 'A' + (6 - j));
        }
        printf("\n");
    }

    return 0;
}
