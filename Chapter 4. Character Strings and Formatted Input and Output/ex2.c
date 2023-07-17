#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("a) \"%s\"\n", name);
    printf("b) \"%20s\"\n", name);
    printf("c) \"%-20s\"\n", name);
    printf("d) %*s\n", (int) strlen(name) + 3, name);

    return 0;
}