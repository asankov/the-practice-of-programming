#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval
{
    char *name;
    int value;
    Nameval *left;  /* lesser */
    Nameval *right; /* greater */
};

Nameval *newleaf(char *name, int value);
void printtree(Nameval *treep, void *arg);
Nameval *insert(Nameval *treep, Nameval *newp);
Nameval *lookup(Nameval *treep, char *name);
Nameval *nrlookup(Nameval *treep, char *name);
void applyinorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg);
void applypreorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg);
void applypostorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg);

void printtree(Nameval *treep, void *arg)
{
    printf((char *)arg, treep->name, treep->value);
}

Nameval *newleaf(char *name, int value)
{
    Nameval *n = (Nameval *)malloc(sizeof(Nameval));

    n->name = name;
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}
/* insert: insert newp in treep and return treep */
Nameval *insert(Nameval *treep, Nameval *newp)
{
    if (treep == NULL)
        return newp;

    int cmp = strcmp(treep->name, newp->name);
    if (cmp == 0)
    {
        printf("value (%s) already present at treep.", newp->name);
        return treep;
    }
    if (cmp < 0)
        treep->left = insert(treep->left, newp);
    else
        treep->right = insert(treep->right, newp);
    return treep;
}

/* lookup: looks up name in treep and return the node that contains it*/
Nameval *lookup(Nameval *treep, char *name)
{
    if (treep == NULL)
        return NULL;

    int cmp = strcmp(treep->name, name);
    if (cmp == 0)
        return treep;
    if (cmp < 0)
        return lookup(treep->left, name);
    else
        return lookup(treep->right, name);
}

/* nrlookup: non-recursive implementation of lookup */
Nameval *nrlookup(Nameval *treep, char *name)
{
    while (treep != NULL)
    {
        int cmp = strcmp(treep->name, name);
        if (cmp == 0)
            return treep;
        if (cmp < 0)
            treep = treep->left;
        else
            treep = treep->right;
    }

    return NULL;
}

/* applyinorder: apply fn(arg) in order to all the elements in treep */
void applyinorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg)
{
    if (treep == NULL)
        return;

    applyinorder(treep->left, fn, arg);
    fn(treep, arg);
    applyinorder(treep->right, fn, arg);
}

/* applypostorder: apply fn(arg) post order to all the elements in treep */
void applypostorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg)
{
    if (treep == NULL)
        return;

    applypostorder(treep->left, fn, arg);
    applypostorder(treep->right, fn, arg);
    fn(treep, arg);
}

/* appkypostorder: apply fn(arg) pre-order to all the elements in treep*/
void applypreorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg)
{
    if (treep == NULL)
        return;

    fn(treep, arg);
    applypreorder(treep->left, fn, arg);
    applypreorder(treep->right, fn, arg);
}