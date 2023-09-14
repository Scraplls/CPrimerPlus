/* C Primer Plus. Programming Exercise 13.9
 * Modify the program in Listing 13.3 so that each word is numbered according to the order
 * in which it was added to the ex2_list, starting with 1. Make sure that, when the program is
 * run a second time, new word numbering resumes where the previous numbering left off.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 41
int main(void)
{
    FILE *fp;
    char ch;
    char words[MAX];
    int count = 0;
    long pos;

    if ((fp = fopen("wordy.txt", "a+")) == NULL)
    {
        fprintf(stdout,"Can't open \"wordy.txt\" file.\n");
        exit(EXIT_FAILURE);
    }

    /* seek for a counter on the last line */
    fseek(fp, 0L, SEEK_END);
    pos = ftell(fp);
    for(int i = 3; i <= pos; i++)
    {
        fseek(fp, -i, SEEK_END);
        ch = getc(fp);
        if(ch == '\n')
            break;
    }
    fscanf(fp, "%d", &count); /* get last counter */
    fseek(fp, 0, SEEK_END);

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d %s\n", ++count, words);
    puts("File contents:");
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        fputs(words, stdout);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    return 0;
}