/* C Primer Plus. Programming Exercise 8.3
 * Write a program that reads input as a stream of characters until encountering EOF .
 * Have it reported the number of uppercase letters, the number of lowercase letters, and the
 * number of other characters in the input. You may assume that the numeric values for the
 * lowercase letters are sequential and assume the same for uppercase. Or, more portably,
 * you can use appropriate classification functions from the ctype.h library.
 */
#include <stdio.h>

int main(void)
{
    char ch;
    int upper, lower, other;

    upper = lower = other = 0;
    while ((ch = getchar()) != EOF){
        if (ch >= 'A' && ch <= 'Z')
            upper++;
        else if (ch >= 'a' && ch <= 'z')
            lower++;
        else
            other++;
    }

    printf("Uppercase letters count: %d\n", upper);
    printf("Lowercase letters count: %d\n", lower);
    printf("Other letters count: %d\n", other);

    return 0;
}