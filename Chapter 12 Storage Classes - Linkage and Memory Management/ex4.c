/* C Primer Plus. Programming Exercise 12.4
 * Write and test in a loop a function that returns the number of times it has been called.
 */
#include <stdio.h>
int callme();

int main(void)
{
    int n, c;
    printf("How many times do you want the function to be called: ");
    scanf("%d", &n);
    while (n > 0)
    {
        printf("callme()\n");
        c = callme();
        n--;
    }
    printf("Function callme() was called %d times.\n", c);

    return 0;
}

int callme()
{
    static int count = 0;
    count++;
    return count;
}