#include <stdio.h>
#include <string.h>

int main(void)
{
    char fname[40], lname[40];
    int fname_length, lname_length;

    printf("- What is your first name?\n- ");
    scanf("%s", fname);
    printf("- What is your last name?\n- ");
    scanf("%s", lname);

    fname_length = strlen(fname);
    lname_length = strlen(lname);

    printf("%s %s\n", fname, lname);
    printf("%*d %*d\n", fname_length, fname_length, lname_length, lname_length);
    printf("%s %s\n", fname, lname);
    printf("%-*d %-*d\n", fname_length, fname_length, lname_length, lname_length);

    return 0;
}