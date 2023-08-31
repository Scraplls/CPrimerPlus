/* C Primer Plus. Programming Exercise 13.1
 * Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user’s
 * response instead of using command-line arguments.
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    char fname[FILENAME_MAX];
    puts("Enter a filename to get it's size: ");
    scanf("%s", fname);

    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", fname, count);
    return 0;
}