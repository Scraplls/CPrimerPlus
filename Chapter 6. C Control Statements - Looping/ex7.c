/* C Primer Plus. Programming Exercise 6.7
 * Write a program that reads a single word into a character array and then prints the word
 * backward. Hint: Use strlen() ( Chapter 4) to compute the index of the last character in
 * the array.
 */
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main(void){
    char word[MAX_LENGTH];
    int i;

    printf("Type any single word: ");
    scanf("%s", word);

    printf("%s backwards is ", word);
    for(i = strlen(word) - 1; i >= 0; i--){
        printf("%c", word[i]);
    }
    printf("\n");

    return 0;
}