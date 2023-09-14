#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int* mem = (int*) malloc(5 * sizeof(int));
    free(mem);
    return 0;
}