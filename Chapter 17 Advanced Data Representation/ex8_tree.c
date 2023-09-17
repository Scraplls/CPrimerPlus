/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ex8_tree.h"
/* local data type */
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;
/* protototypes for local functions */
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode (Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void (* pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * trnode);
/* function definitions */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}
bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}
bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}
int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}
bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Trnode * found;
    List * list;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr,"Tree is full\n");
        return false; /* early return */
    }
    if ((found = SeekItem(pi, ptree).child) != NULL)
    {
        list = &found->list;
        AddItemToList(*pi, list);
        ptree->size++;
        return true;
    }
    new_node = MakeNode(pi); /* points to new node */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false; /* early return */
    }
    /* succeeded in creating a new node */
    ptree->size++;
    if (ptree->root == NULL) /* case 1: tree is empty */
        ptree->root = new_node; /* new node is tree root */
    else /* case 2: not empty */
        AddNode(new_node,ptree->root); /* add node to tree */
    return true; /* successful return */
}
bool InTree(const Item * pi, const Tree * ptree, List * plist)
{
    Trnode * node = SeekItem(pi, ptree).child;
    if(node == NULL)
        return false;
    *plist = node->list;
    return true;
}
bool DeleteItem(const Item * pi, Tree * ptree, int (*pEqual) (Item, Item))
{
    Pair look;
    int count;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    count = (int) ListItemCount(&look.child->list);
    if(count == 1)
    {
        if (look.parent == NULL) /* delete root list */
            DeleteNode(&ptree->root);
        else if (look.parent->left == look.child)
            DeleteNode(&look.parent->left);
        else
            DeleteNode(&look.parent->right);
    }
    else
    {
        DeleteItemFromList(*pi, &look.child->list, pEqual);
    }
    ptree->size--;

    return true;
}
void Traverse (const Tree * ptree, void (* pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}
void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}
/* local functions */
static void InOrder(const Trnode * root, void (* pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        TraverseList(&root->list, pfun);
        InOrder(root->right, pfun);
    }
}
static void DeleteAllNodes(Trnode * trnode)
{
    Trnode * pright;
    if (trnode != NULL)
    {
        pright = trnode->right;
        DeleteAllNodes(trnode->left);
        EmptyTheList(&trnode->list);
        free(trnode);
        DeleteAllNodes(pright);
    }
}
static void AddNode(Trnode * new_node, Trnode * root)
{
    if (ToLeft(&new_node->list.head->item, &root->list.head->item))
    {
        if (root->left == NULL) /* empty subtree */
            root->left = new_node; /* so add node here */
        else
            AddNode(new_node, root->left);/* else process subtree*/
    }
    else if (ToRight(&new_node->list.head->item, &root->list.head->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else /* should be no duplicates */
    {
        fprintf(stderr,"location error in AddNode()\n");
        exit(1);
    }
}
 static bool ToLeft(const Item * i1, const Item * i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else
        return false;
}
static bool ToRight(const Item * i1, const Item * i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else
        return false;
}
static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node;
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        InitializeList(&new_node->list);
        AddItemToList(*pi, &new_node->list);
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}
static Pair SeekItem(const Item * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if (look.child == NULL)
        return look; /* early return */
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->list.head->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->list.head->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else /* must be same if not to left or right */
            break; /* look.child is address of node with list */
    }
    return look; /* successful return */
}
static void DeleteNode(Trnode **ptr)
/* ptr is address of parent member pointing to target node */
{
    Trnode * temp;
    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        EmptyTheList(&temp->list);
        free(temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        EmptyTheList(&temp->list);
        free(temp);
    }
    else /* deleted node has two children */
    {
        /* find where to reattach right subtree */
        for (temp = (*ptr)->left; temp->right != NULL;
             temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr =(*ptr)->left;
        EmptyTheList(&temp->list);
        free(temp);
    }
}