/* C Primer Plus. Programming Exercise 6.5
 * Have a program request the user to enter an uppercase letter. Use nested loops to produce
 * a pyramid pattern like this:
 *     A
 *    ABA
 *   ABCBA
 *  ABCDCBA
 * ABCDEDCBA
 * The pattern should extend to the character entered. For example, the preceding pattern
 * would result from an input value of E. Hint: Use an outer loop to handle the rows. Use
 * three inner loops in a row, one to handle the spaces, one for printing letters in ascending
 * order, and one for printing letters in descending order. If your system doesn’t use ASCII
 * or a similar system that represents letters in strict number order, see the suggestion in
 * programming exercise 3.
 */
#include <stdio.h>

int main(void){
    char middle;
    int offset;
    int i, j;

    printf("Enter an uppercase letter [A-Z] to print a pyramid: ");
    scanf(" %c", &middle);
    while (middle < 'A' || middle > 'Z'){
        printf("Error! That's not an uppercase letter!\n");
        printf("Enter an uppercase letter [A-Z] to print a pyramid: ");
        scanf(" %c", &middle);
    }

    offset = middle - 'A';
    for(i = 0; i <= offset; i++){
        for(j = 0; j < offset - i; j++)
            printf(" ");
        for(j = 0; j < i + 1; j++)
            printf("%c", 'A' + j);
        for(j = j - 2; j >= 0; j--)
            printf("%c", 'A' + j);
        printf("\n");
    }

    return 0;
}

