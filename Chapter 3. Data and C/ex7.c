#include <stdio.h>

int main(void)
{
    int cm;
    float inch;

    printf("Enter your height in cm: ");
    scanf("%d", &cm);
    inch = 2.54f * cm;
    printf("Height: %.2f in", inch);

    return 0;
}

