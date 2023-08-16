/* C Primer Plus. Programming Exercise 11.8
 * Write a function called string_in() that takes two string pointers as arguments. If
 * the second string is contained in the first string, have the function return the address
 * at which the contained string begins. For instance, string_in("hats", "at") would
 * return the address of the a in hats. Otherwise, have the function return the null pointer.
 * Test the function in a complete program that uses a loop to provide input values for
 * feeding to the function.
 */
#include <stdio.h>
char* string_in(char* s1, char* s2);

int main(void)
{
    printf("Starts at %c\n", *string_in("hats", "s"));
    return 0;
}

char* string_in(char* s1, char* s2)
{
    int j;
    j = 0;
    while (*s1 != '\0')
    {
        if(*(s2 + j) == '\0'){
            return s1 - j;
        }
        else if(*s1 == *(s2 + j))
            j++;
        else
            j = 0;
        s1++;
    }
    return NULL;
}