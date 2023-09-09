/* C Primer Plus. Programming Exercise 6.1
 * Write a program that creates an array with 26 elements and stores the 26 lowercase
 * letters in it. Also have it show the array contents.
 */
#include <stdio.h>

int main(void){
    char letters[26];

    for(int i = 0; i < 26; i++){
        letters[i] = 'a' + i;
    }

    for(int i = 0; i < 26; i++){
        printf("%c", letters[i]);
    }
    printf("\n");

    return 0;
}
