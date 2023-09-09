#include <stdio.h>

int main(void)
{
    char name[40];
    float height;

    printf("Enter your name and your height (in cm): ");
    scanf("%s %f", name, &height);

    printf("%s, you are %.3fm tall\n", name, height / 10);

    return 0;
}