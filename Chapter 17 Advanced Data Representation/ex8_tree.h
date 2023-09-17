/* tree.h -- binary search tree */
/* no duplicate items are allowed in this tree */
#ifndef CPRIMERPLUS_EX8_TREE_H
#define CPRIMERPLUS_EX8_TREE_H
#include <stdbool.h>
#include "ex8_list.h"
#define MAXITEMS 10
typedef struct trnode
{
    List list;
    struct trnode * left; /* pointer to right branch */
    struct trnode * right; /* pointer to left branch */
} Trnode;
typedef struct tree
{
    Trnode * root; /* pointer to root of tree */
    int size; /* number of items in tree */
} Tree;

void InitializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pi, Tree * ptree);

bool InTree(const Item * pi, const Tree * ptree, List * plist);

bool DeleteItem(const Item * pi, Tree * ptree, int (*pEqual) (Item, Item));

void Traverse (const Tree * ptree, void (* pfun)(Item item));

void DeleteAll(Tree * ptree);
#endif
