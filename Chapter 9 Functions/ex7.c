/* C Primer Plus. Programming Exercise 9.7
 * Write a program that reads characters from the standard input to end-of-file. For each
 * character, have the program report whether it is a letter. If it is a letter, also report
 * its numerical location in the alphabet. For example, c and C would both be letter 3.
 * Incorporate a function that takes a character as an argument and returns the numerical
 * location if the character is a letter and that returns –1 otherwise.
 */
#include <stdio.h>
int findletter(char ch);

int main(void){
    char ch;
    int loc;

    while ((ch = getchar()) != EOF && ch != '\n'){
        if((loc = findletter(ch)) > -1)
            printf("%c is a letter with numeric location of %d\n", ch, loc);
        else
            printf("%c is not a letter\n", ch);
    }
    return 0;
}

int findletter(char ch){
    if(ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 1;
    if(ch >= 'a' && ch <= 'z')
        return ch - 'a' + 1;
    return -1;
}