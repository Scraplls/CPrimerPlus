#include <stdlib.h>
#include "ex8_list.h"
/* local function prototype */
static void CopyToNode(Item item, Node * pnode);
/* interface functions */
/* set the list to empty */
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->end = NULL;
}
/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}
/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;
    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}
/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head; /* set to start of list */
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next; /* set to next node */
    }
    return count;
}
/* creates node to hold list and adds it to the end of */
/* the list pointed to by plist (slow implementation) */
bool AddItemToList(Item item, List * plist)
{
    Node * pnew;
    Node * scan = plist->head;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false; /* quit function on failure */
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)/* empty list, so place */
        plist->head = pnew; /* pnew at head of list */
    else
        plist->end->next = pnew;
    plist->end = pnew; /* pnew at end of list */

    return true;
}

bool DeleteItemFromList(Item item, List * plist, int (*pEqual) (Item, Item))
{
    Node * scan = plist->head;
    if (scan == NULL)
        return false;
    if (pEqual(item, scan->item))
    {
        EmptyTheList(plist);
        return true;
    }

    while (scan->next != NULL)
    {
        if (pEqual(item, scan->next->item))
        {
            scan->next = scan->next->next;
            break;
        }
        scan = scan->next;
    }

    return true;
}

/* visit each node and execute function pointed to by pfun */
void TraverseList(const List * plist, void (* pfun)(Item item) )
{
    Node * pnode = plist->head; /* set to start of list */
    while (pnode != NULL)
    {
        (*pfun)(pnode->item); /* apply function to list */
        pnode = pnode->next; /* advance to next list */
    }
}
/* free memory allocated by malloc() */
/* set list pointer to NULL */
void EmptyTheList(List * plist)
{
    Node * psave;
    Node * pnode = plist->head; /* set to start of list */
    while (pnode != NULL)
    {
        psave = pnode->next; /* save address of next node */
        free(pnode); /* free current node */
        pnode = psave; /* advance to next node */
    }
    plist->head = NULL;
    plist->end = NULL;
}
/* local function definition */
/* copies an list into a node */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item; /* structure copy */
}