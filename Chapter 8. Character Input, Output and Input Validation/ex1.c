/* C Primer Plus. Programming Exercise 8.1
 * Devise a program that counts the number of characters in its input up to the end of file.
 *
 * Note: Several of the following programs ask for input to be terminated by EOF. If your operating
 * system makes redirection awkward or impossible, use some other test for terminating input,
 * such as reading the & character.
 */
#include <stdio.h>

int main(void){
    int count;
    int ch;

    count = 0;
    while ((ch = getchar()) != '&' && ch != EOF){
        count++;
    }
    printf("Characters written: %d\n", count);
    return 0;
}