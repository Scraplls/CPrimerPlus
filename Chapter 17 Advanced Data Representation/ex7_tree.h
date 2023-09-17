/* tree.h -- binary search tree */
/* no duplicate items are allowed in this tree */
#ifndef CPRIMERPLUS_EX7_TREE_H
#define CPRIMERPLUS_EX7_TREE_H
#include <stdbool.h>

typedef struct item
{
    char * word;
    int count;
} Item;
typedef struct node
{
    Item item;
    struct node * left; /* pointer to right branch */
    struct node * right; /* pointer to left branch */
} Node;
typedef struct tree
{
    Node * root; /* pointer to root of tree */
    int size; /* number of items in tree */
} Tree;
/* function prototypes */
/* operation: initialize a tree to empty */
/* preconditions: ptree points to a tree */
/* postconditions: the tree is initialized to empty */
void InitializeTree(Tree * ptree);
/* operation: determine if tree is empty */
/* preconditions: ptree points to a tree */
/* postconditions: function returns true if tree is */
/* empty and returns false otherwise */
bool TreeIsEmpty(const Tree * ptree);
/* operation: determine if tree is full */
/* preconditions: ptree points to a tree */
/* postconditions: function returns true if tree is */
/* full and returns false otherwise */
bool TreeIsFull(const Tree * ptree);
/* operation: determine number of items in tree */
/* preconditions: ptree points to a tree */
/* postconditions: function returns number of items in */
/* tree */
int TreeItemCount(const Tree * ptree);
/* operation: add an list to a tree */
/* preconditions: pi is address of list to be added */
/* ptree points to an initialized tree */
/* postconditions: if possible, function adds list to */
/* tree and returns true; otherwise, */
/* the function returns false */
bool AddItem(const Item * pi, Tree * ptree);
/* operation: find an list in a tree */
/* preconditions: pi points to an list */
/* ptree points to an initialized tree */
/* postconditions: function returns true if list is in */
/* tree and returns false otherwise */
bool InTree(const Item * pi, const Tree * ptree);
/* operation: delete an list from a tree */
/* preconditions: pi is address of list to be deleted */
/* ptree points to an initialized tree */
/* postconditions: if possible, function deletes list */
/* from tree and returns true; */
/* otherwise the function returns false*/
bool DeleteItem(const Item * pi, Tree * ptree);
/* operation: apply a function to each list in */
/* the tree */
/* preconditions: ptree points to a tree */
/* pfun points to a function that takes*/
/* an Item argument and has no return */
/* value */
/* postcondition: the function pointed to by pfun is */
/* executed once for each list in tree */
void Traverse(const Tree * ptree, void (* pfun)(Item * item));
/* operation: delete everything from a tree */
/* preconditions: ptree points to an initialized tree */
/* postconditions: tree is empty */
void DeleteAll(Tree * ptree);
#endif
