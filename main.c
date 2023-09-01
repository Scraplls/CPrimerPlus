#include <stdio.h>

int main(void)
{
    char ch;
    FILE *fp;
    fp = fopen("readme.md", "r");
    /* seek for a counter on the last line */
    fseek(fp, -2, SEEK_END);
    ch = getc(fp);
    while (ch != EOF)
        ch = getc(fp);
    fclose(fp);
    return 0;
}