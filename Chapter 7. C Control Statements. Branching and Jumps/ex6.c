/* C Primer Plus. Programming Exercise 7.6
 * Write a program that reads input up to # and reports the number of times that the sequence ei occurs.
 */
#include <stdio.h>

int main(void){
    char ch, prev;
    int ei_cnt;

    ei_cnt = 0;
    prev = 0;
    while ((ch = getchar()) != '#'){
        if(prev == 'e' && ch == 'i')
            ei_cnt++;
        prev = ch;
    }
    printf("\nSequence 'ei' occurs %d times in the text\n", ei_cnt);

    return 0;
}

