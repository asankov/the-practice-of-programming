#include <stdio.h>

#include "trees.c"

void print_sorted(Nameval *treep);

Nameval *elems[100];

int main()
{
    Nameval *treep = NULL;
    treep = insert(treep, newleaf("Item2", 0));
    treep = insert(treep, newleaf("Item", 0));
    treep = insert(treep, newleaf("Item4", 0));
    treep = insert(treep, newleaf("Item3", 0));
    treep = insert(treep, newleaf("Item5", 0));

    print_sorted(treep);
    printf("\n");
}

void print_sorted(Nameval *treep)
{
    if (treep == NULL)
        return;

    print_sorted(treep->right);
    printf("%s, ", treep->name);
    print_sorted(treep->left);
}