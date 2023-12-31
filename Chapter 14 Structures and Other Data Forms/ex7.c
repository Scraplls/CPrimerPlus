/* C Primer Plus. Programming Exercise 14.7
 * Modify Listing 14.14 so that as each record is read from the file and shown to you, you
 * are given the chance to delete the record or to modify its contents. If you delete the
 * record, use the vacated array position for the next record to be read. To allow changing
 * the existing contents, you’ll need to use the "r+b" mode instead of the "a+b" mode, and
 * you’ll have to pay more attention to positioning the file pointer so that appended records
 * don’t overwrite existing records. It’s simplest to make all changes in the data stored in
 * program memory and then write the final set of information to the file. One approach to
 * keeping track is to add a member to the book structure that indicates whether it is to be
 * deleted.
 */
/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */

struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);
void changebook(struct book *book);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    int choice;
    FILE * pbooks;
    int size = sizeof (struct book);
    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n",library[count].title,
               library[count].author, library[count].value);
        count++;
        puts("Menu select: ");
        puts("1. change book contents   2. delete record");
        puts("3. read next");
        choice = getchar();
        while (getchar() != '\n')
            continue;
        switch (choice) {
            case '1':
                changebook(&library[count]);
                break;
            case '2':
                count--;
                break;
            default:
                break;
        }
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title,
                   library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount,
               pbooks);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}

void changebook(struct book *book)
{
    printf("Enter new title: ");
    s_gets(book->title, MAXTITL);
    printf("Enter new author: ");
    s_gets(book->author, MAXAUTL);
    printf("Enter new value: ");
    scanf("%f", &book->value);
    while (getchar() != '\n')
        continue;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}