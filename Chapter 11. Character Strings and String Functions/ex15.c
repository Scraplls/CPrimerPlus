/* C Primer Plus. Programming Exercise 11.15
 * Use the character classification functions to prepare an implementation of atoi(); have
 * this version return the value of 0 if the input string is not a pure number.
 */
#include <stdio.h>
#define SIZE 100

int myatoi(char str[SIZE]);

int main(void)
{
    char str[SIZE];
    int res;

    puts("Enter an integer number: ");
    gets(str);
    res = myatoi(str);
    printf("You've entered a %d\n", res);

    return 0;
}

int myatoi(char str[SIZE])
{
    int i, res, neg;
    i = 0;
    neg = 0;
    res = 0;
    if(str[i] == '-')
    {
        neg = 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if(neg)
        res = res * -1;
    return res;
}