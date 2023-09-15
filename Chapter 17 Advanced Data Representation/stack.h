#ifndef CPRIMERPLUS_STACK_H
#define CPRIMERPLUS_STACK_H
#include <stdbool.h>
typedef struct item
{
    char character;
} Item;
typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct stack
{
    Node *top;
    int items;
} Stack;
/* operation: initialize the stack */
/* precondition: ps points to a stack */
/* postcondition: stack is initialized to being empty */
void InitializeStack(Stack * ps);
/* operation: check if stack is full */
/* precondition: ps points to previously initialized stack */
/* postcondition: returns True if stack is full, else False */
bool StackIsFull(const Stack * ps);
/* operation: check if stack is empty */
/* precondition: ps points to previously initialized stack */
/* postcondition: returns True if stack is empty, else False */
bool StackIsEmpty(const Stack * ps);
/* operation: determine number of items in stack */
/* precondition: ps points to previously initialized stack */
/* postcondition: returns number of items in stack */
int StackItemCount(const Stack * ps);
/* operation: add item on top of stack */
/* precondition: ps points to previously initialized stack */
/* item is to be placed at top of stack */
/* postcondition: if stack is not empty, item is placed at */
/* the top of stack and function returns */
/* True; otherwise, queue is unchanged and */
/* function returns False */
bool Push(Item item, Stack * ps);
/* operation: remove item from top of stack */
/* precondition: ps points to previously initialized stack */
/* postcondition: if stack is not empty, item at top of */
/* stack is copied to *pitem and deleted from */
/* stack, and function returns True; if the */
/* operation empties the stack, the stack is */
/* reset to empty. If the stack is empty to */
/* begin with, stack is unchanged and the */
/* function returns False */
bool Pop(Item *pitem, Stack * ps);
/* operation: empty the stack */
/* precondition: ps points to previously initialized stack */
/* postconditions: the stack is empty */
void EmptyTheStack(Stack * ps);
#endif
