/* C Primer Plus. Programming Exercise 14.3
 * Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in
 * the order entered, then alphabetized by title, and then in order of increased value
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);
/* Sort books array by title, store result in dest */
void sort_by_title(int n, struct book books[n], struct book **dest);
/* Sort books array by value, store result in dest */
void sort_by_value(int n, struct book books[n], struct book **dest);

int main(void)
{
    struct book library[MAXBKS]; /* MAXBKS-element array of structure book */
    /* allocate MAXBKS * (struct book*) pointers to store addresses of sorted books*/
    struct book** dest = (struct book **)
            malloc(sizeof(struct book*) * MAXBKS);
    if(dest == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);

        sort_by_title(count, library, dest);
        printf("Ordered by title books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", dest[index]->title,
                   dest[index]->author, dest[index]->value);

        sort_by_value(count, library, dest);
        printf("Ordered by value books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", dest[index]->title,
                   dest[index]->author, dest[index]->value);
    }
    else
        printf("No books? Too bad.\n");

    free(dest);
    return 0;
}

void sort_by_title(int n, struct book books[n], struct book **dest)
{
    int i, j;
    /* initialize dest array by copying addresses of books array*/
    for (i = 0; i < n; i++)
        dest[i] = &books[i];
    struct book *temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (dest[i]->title[0] > dest[j]->title[0])
            {
                temp = dest[j];
                dest[j] = dest[i];
                dest[i] = temp;
            }
}

void sort_by_value(int n, struct book books[n], struct book **dest)
{
    int i, j;
    /* initialize dest array by copying addresses of books array*/
    for (i = 0; i < n; i++)
        dest[i] = &books[i];
    struct book *temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (dest[i]->value > dest[j]->value)
            {
                temp = dest[j];
                dest[j] = dest[i];
                dest[i] = temp;
            }
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