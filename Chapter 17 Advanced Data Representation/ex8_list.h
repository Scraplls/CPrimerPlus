#ifndef CPRIMERPLUS_EX8_LIST_H
#define CPRIMERPLUS_EX8_LIST_H
#include <stdbool.h>

#define SLEN 20
/* redefine Item as appropriate */
typedef struct item
{
    char petname[SLEN];
    char petkind[SLEN];
} Item;
typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct list
{
    Node * head; /* points to head of list */
    Node * end; /* points to end of list */
} List;

void InitializeList(List * plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItemToList(Item item, List * plist);

bool DeleteItemFromList(Item item, List * plist, int (*pComp) (Item, Item));

void TraverseList (const List *plist, void (* pfun)(Item item) );

void EmptyTheList(List * plist);
#endif