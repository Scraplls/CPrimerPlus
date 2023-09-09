#include <stdio.h>

int main(void)
{
    unsigned quarts;
    float molecules;

    printf("Enter an amount of water in quarts: ");
    scanf("%u", &quarts);

    molecules = (950.0f / 3e-23f) * quarts;

    printf("There are %e molecules in %u quarts of water.", molecules, quarts);


    return 0;
}
