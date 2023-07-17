#include <stdio.h>
#include <float.h>

int main(void)
{
    float f = 1.0f/3.0f;
    double d = f;

    printf("%.4f %.12f %.16f\n", f, f, f);
    printf("%.4f %.12f %.16f\n", d, d, d);
    printf("%d\n", FLT_DIG);
    printf("%d\n", DBL_DIG);

    return 0;
}