/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "ex3_list.h"
/* interface functions */
/* set the list to empty */
void InitializeList(List * plist)
{
    plist->items = 0;
}
/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}
/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    if (plist->items < MAXSIZE)
        return false;
    else
        return true;
}
/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}
/* assign list to a current free position in list*/
/* the list pointed to by plist (fast implementation) */
bool AddItem(Item item, List * plist)
{
    if (ListIsFull(plist))
        return false; /* quit function on full */
    int index = plist->items;
    plist->entries[index] = item;
    plist->items++;
    return true;
}
/* visit each list and execute function pointed to by pfun */
void Traverse (const List * plist, void (* pfun)(Item item) )
{
    for (int index = 0; index < plist->items; index++)
        (*pfun)(plist->entries[index]); /* apply function to list */
}