#include "lists.c"

int main()
{
    Nameval *list = NULL;

    list = addfront(list, newitem("Ivan", 2));
    list = addfront(list, newitem("Gosho", 3));
    list = addend(list, newitem("Petran", 4));

    Nameval *nv = lookup(list, "Gosho");
    if (strcmp(nv->name, "Gosho") != 0 || nv->value != 3)
    {
        printf("Got wrong result when searching for Gosho");
        return 1;
    }
    printf("Succesfully found Gosho in list\n");

    apply(list, printnv, "%s: %d, ");
    printf("\n");

    int i = 0;
    apply(list, incounter, &i);
    printf("there are %d elements in the list\n", i);

    list = delitem(list, "Ivan");
    apply(list, printnv, "%s: %d, ");
    printf("\n");

    list = addfront(list, newitem("Georgi", 3));
    apply(list, printnv, "%s: %d, ");
    printf("\n");

    Nameval *newlist = copy(list);
    printf("printing list\n");
    apply(list, printnv, "%s: %d, ");
    printf("\n");
    printf("printing newlist\n");
    apply(newlist, printnv, "%s: %d, ");
    printf("\n");

    list = delitem(list, "Gosho");
    printf("printing list\n");
    apply(list, printnv, "%s: %d, ");
    printf("\n");
    printf("printing newlist\n");
    apply(newlist, printnv, "%s: %d, ");
    printf("\n");

    Nameval *merged = merge(list, newlist);
    printf("printing merged\n");
    apply(merged, printnv, "%s: %d, ");
    printf("\n");

    insert_after(merged, "Gosho", newitem("Gosho 2", 5));
    printf("printing merged\n");
    apply(merged, printnv, "%s: %d, ");
    printf("\n");

    insert_before(merged, "Georgi", newitem("Georgi 0.5", 5));
    printf("printing merged\n");
    apply(merged, printnv, "%s: %d, ");
    printf("\n");

    freeall(list);

    return 0;
}