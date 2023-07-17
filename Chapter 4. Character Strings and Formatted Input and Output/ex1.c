#include <stdio.h>

int main(void)
{
    char fname[40], lname[40];

    printf("- What is your first name?\n- ");
    scanf("%s", fname);
    printf("- What is your last name?\n- ");
    scanf("%s", lname);

    printf("- Nice to meet you, %s %s.\n", lname, fname);

    return 0;
}