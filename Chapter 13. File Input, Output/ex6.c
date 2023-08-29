/* C Primer Plus. Programming Exercise 13.6
 * Programs using command-line arguments rely on the user’s memory of how to use them
 * correctly. Rewrite the program in Listing 13.2 so that, instead of using command-line
 * arguments, it prompts the user for the required information.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(void)
{
    FILE *in, *out;
    int ch;
    char input[LEN];
    char name[LEN];
    int count = 0;
    puts("Enter an input filename: ");
    if(!scanf("%s", input))
    {
        fprintf(stderr, "Input error!\n");
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(input, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", input);
        exit(EXIT_FAILURE);
    }
    strncpy(name, input, LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name,".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    return 0;
}