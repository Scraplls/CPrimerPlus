#include <stdio.h>

int main(void)
{
    float speed, size, time;

    printf("Enter your download speed (in Mb/s) and file size (in MB): ");
    scanf("%f %f", &speed, &size);

    time = size / (speed / 8);
    printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds.\n", speed, size, time);

    return 0;
}