/* C Primer Plus. Programming Exercise 17.8
 * Modify the Pet Club program so that all pets with the same name are stored in a list in
 * the same node. When the user chooses to find a pet, the program should request the pet
 * name and then list all pets (along with their kinds) having that name.
 */
/* petclub.c -- use a binary search tree */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ex8_tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpets(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

int petsEqual(Item pet1, Item pet2);

int main(void)
{
    Tree pets;
    char choice;
    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a' : addpet(&pets);
                break;
            case 'l' : showpets(&pets);
                break;
            case 'f' :
                findpets(&pets);
                break;
            case 'n' : printf("%d pets in club\n",
                              TreeItemCount(&pets));
                break;
            case 'd' : droppet(&pets);
                break;
            default : puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");
    return 0;
}
char menu(void)
{
    int ch;
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet l) show list of pets");
    puts("n) number of pets f) find pets");
    puts("d) delete a pet q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq",ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF) /* make EOF cause program to quit */
        ch = 'q';
    return ch;
}
void addpet(Tree * pt)
{
    Item temp;
    if (TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname,SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind,SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}
void showpets(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}
void printitem(Item item)
{
    printf("Pet: %-19s Kind: %-19s\n", item.petname,
           item.petkind);
}
void findpets(const Tree * pt)
{
    Item temp;
    List * plist = (List *) malloc(sizeof(List*));
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return; /* quit function if tree is empty */
    }
    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    uppercase(temp.petname);
    if (InTree(&temp, pt, plist))
    {
        printf("Here is list of all pets named %s: \n", temp.petname);
        TraverseList(plist, printitem);
    }
    else
        printf("is not a member.\n");
}
void droppet(Tree * pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return; /* quit function if tree is empty */
    }
    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt, petsEqual))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

int petsEqual(Item pet1, Item pet2)
{
    return strcmp(pet1.petname, pet2.petname) == 0 && strcmp(pet1.petkind, pet2.petkind) == 0;
}

void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}