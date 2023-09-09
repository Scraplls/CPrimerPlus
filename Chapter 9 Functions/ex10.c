/* C Primer Plus. Programming Exercise 9.10
 * Generalize the to_binary() function of Listing 9.8 to a to_base_n() function that
 * takes a second argument in the range 2–10. It then should print the number that is its
 * first argument to the number base given by the second argument. For example, to_
 * base_n(129,8) would display 201, the base-8 equivalent of 129. Test the function in a
 * complete program.
 */
#include <stdio.h>
void to_base_n(unsigned long n, unsigned int b);

int main(void)
{
    int valid;
    unsigned long number;
    unsigned int base;

    printf("Enter an integer and base to convert (q to quit):\n");
    valid = 1;
    valid *= scanf("%lu %u", &number, &base) == 2;
    while (valid)
    {
        printf("Number equivalent in base %d: ", base);
        to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer and base to convert (q to quit):\n");
        valid *= scanf("%lu %u", &number, &base) == 2;
    }
    printf("Done.\n");
    return 0;
}

void to_base_n(unsigned long n, unsigned int b)
{
    int r;
    r = n % b;
    if (n >= b)
        to_base_n(n / b, b);
    putchar('0' + r);
}