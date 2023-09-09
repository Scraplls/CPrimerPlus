#include <stdio.h>

int main(void)
{
    unsigned int years;
    float seconds;

    printf("Enter your age in years: ");
    scanf("%u", &years);

    seconds = 3.156e7f * years;

    printf("Your equivalent age in seconds: %.2f\n", seconds);

    return 0;
}