#include <stdio.h>

#include "trees.c"

char *names[] = {
    "Georgi",
    "Pesho",
    "Bai Tosho"};

int test(int (*fn)(Nameval *), char *description);

int test_insert(Nameval *treep);
int test_lookup(Nameval *treep);
int test_nrlookup(Nameval *treep);
int test_count_inorder(Nameval *treep);
int test_count_preorder(Nameval *treep);
int test_count_postorder(Nameval *treep);

int main()
{
    int res = 0;
    res += test(test_insert, "Insert an element into a tree.");
    res += test(test_lookup, "Look-up an element from the tree.");
    res += test(test_nrlookup, "Look-up an element from the tree (non-recursive).");
    res += test(test_count_inorder, "Count the elements in the tree, walking it in order.");
    res += test(test_count_preorder, "Count the elements in the tree, walking it pre order.");
    res += test(test_count_postorder, "Count the elements in the tree, walking it post order.");

    if (res == 0)
        printf(" ✅✅✅ All the test were executed succesfully. ✅✅✅\n");
    else
        printf(" ❌❌❌There were %d failures❌❌❌\n", res);

    return res;
}

int test(int (*fn)(Nameval *), char *description)
{
    Nameval *treep = NULL;
    treep = insert(treep, newleaf(names[0], 0));
    treep = insert(treep, newleaf(names[1], 0));
    treep = insert(treep, newleaf(names[2], 0));

    int res = fn(treep);
    if (res == 0)
        printf(" ✅ %s\n", description);
    else
        printf(" ❌ %s\n", description);

    return res;
}

void counttree(Nameval *treep, void *arg)
{
    int *ip = (int *)arg;
    (*ip)++;
}

int assert_tree(Nameval *treep, char **expected_names, int N)
{
    int i = 0;
    applyinorder(treep, counttree, &i);

    if (i != N)
    {
        printf("[ERROR] Got length (%d) after insertion, expected %d", i, N);
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        Nameval *el = lookup(treep, expected_names[i]);
        if (el == NULL)
        {
            printf("[ERROR] Got NULL for lookup(treep, %s), expected element to be present", expected_names[i]);
            return 1;
        }
    }

    return 0;
}

int test_insert(Nameval *treep)
{
    char *expected_names[] = {
        "Georgi",
        "Pesho",
        "Bai Tosho",
        "Gosho" /* "Gosho" is to be inserted. */
    };

    treep = insert(treep, newleaf("Gosho", 0));

    return assert_tree(treep, expected_names, sizeof(expected_names) / sizeof(expected_names[0]));
}

int _test_lookup(Nameval *treep, Nameval *(*lookup_fn)(Nameval *treep, char *name))
{
    Nameval *new = newleaf("Todor", 2);
    treep = insert(treep, new);

    Nameval *looked_up = lookup_fn(treep, "Todor");
    if (looked_up == NULL)
    {
        printf("[ERROR] Got NULL for lookup(treep, \"Todor\"), expected element to be present");
        return 1;
    }

    if (strcmp(looked_up->name, "Todor") != 0)
    {
        printf("[ERROR] Got (%s) for lookup(treep, \"Todor\")->name, expected \"Todor\"", looked_up->name);
        return 1;
    }
    if (looked_up->value != 2)
    {
        printf("[ERROR] Got (%d) for lookup(treep, \"Todor\")->value, expected (2)", looked_up->value);
        return 1;
    }

    return 0;
}

int test_lookup(Nameval *treep)
{
    return _test_lookup(treep, lookup);
}

int test_nrlookup(Nameval *treep)
{
    return _test_lookup(treep, nrlookup);
}

int _test_count(Nameval *treep, void (*walk_fn)(Nameval *treep, void (*fn)(Nameval *, void *), void *arg))
{
    treep = insert(treep, newleaf("one more", 0));
    treep = insert(treep, newleaf("two more", 0));
    treep = insert(treep, newleaf("three more", 0));

    int c = 0;
    walk_fn(treep, counttree, &c);

    if (c != 6)
    {
        printf("[ERROR] Got (%d) for tree count, expected 6", c);
    }

    return 0;
}

int test_count_inorder(Nameval *treep)
{
    return _test_count(treep, applyinorder);
}

int test_count_preorder(Nameval *treep)
{
    return _test_count(treep, applypreorder);
}

int test_count_postorder(Nameval *treep)
{
    return _test_count(treep, applypostorder);
}
