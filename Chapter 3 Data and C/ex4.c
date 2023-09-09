#include <stdio.h>

int main(void)
{
    float value;

    printf("Enter a floating-point value: ");
    scanf("%f", &value);

    printf("fixed-point notation: %.6f\n", value);
    printf("exponential notation: %e\n", value);
    printf("p notation: %a\n", value);

    return 0;
}