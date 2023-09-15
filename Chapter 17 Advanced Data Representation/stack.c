/* queue.c -- the Queue type implementation*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/* local functions */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);
void InitializeStack(Stack * ps)
{
    ps->top = NULL;
    ps->items = 0;
}
bool StackIsFull(const Stack * ps)
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
bool StackIsEmpty(const Stack * ps)
{
    return ps->items == 0;
}
int StackItemCount(const Stack * ps)
{
    return ps->items;
}
bool Push(Item item, Stack * ps)
{
    Node * pnew;
    if (StackIsFull(ps))
        return false;
    pnew = (Node *) malloc( sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (StackIsEmpty(ps))
        ps->top = pnew;
    else
        pnew->next = ps->top; /* link at top of stack */
    ps->top = pnew; /* record location of top */
    ps->items++; /* one more item in stack */
    return true;
}
bool Pop(Item * pitem, Stack * ps)
{
    Node * pnode;
    if (StackIsEmpty(ps))
        return false;
    CopyToItem(ps->top, pitem);
    pnode = ps->top;
    ps->top = ps->top->next;
    free(pnode);
    ps->items--;
    if (ps->items == 0)
        ps->top = NULL;
    return true;
}
/* empty the stack */
void EmptyTheStack(Stack * ps)
{
    Item dummy;
    while (!StackIsEmpty(ps))
        Pop(&dummy, ps);
}
/* Local functions */
static void CopyToNode(Item item, Node * pn)
{
    pn->item = item;
}
static void CopyToItem(Node * pn, Item * pi)
{
    *pi = pn->item;
}
