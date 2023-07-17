#include <stdio.h>

int main(void)
{
    float number;

    printf("Type any floating-point number: ");
    scanf("%f", &number);

    printf("a) decimal-point notation: %.1f, exponential notation: %.1e\n", number, number);
    printf("b) decimal-point notation: %+.3f, exponential notation: %.3E", number, number);

    return 0;
}