/* C Primer Plus. Programming Exercise 17.5
 * Write a program that lets you input a string. The program then should push the
 * characters of the string onto a stack, one by one (see review question 5), and then pop
 * the characters from the stack and display them. This results in displaying the string in
 * reverse order.
 */
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define STRLEN 40
char * s_gets(char *, int);

int main(void)
{
    Stack stack;
    Stack * ps;
    Item item;
    char buf[STRLEN + 1];

    ps = &stack;
    InitializeStack(ps);
    printf("Enter a string to push it to the stack:\n");
    s_gets(buf, STRLEN + 1);

    Push((Item) {'\0'}, ps);
    for(int i = 0; buf[i] != '\0'; i++)
        Push((Item) {buf[i]}, ps);
    printf("Reversed string from stack: ");
    while(Pop(&item, ps))
        printf("%c", item.character);
    printf("\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}