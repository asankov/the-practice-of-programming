#include "lists.c"

Nameval *reverse_iter(Nameval *list);
Nameval *reverse_rec(Nameval *list);
struct Nameval *recursiveReverseLL(struct Nameval *first);

int main()
{
    Nameval *list = NULL;

    list = addfront(list, newitem("Ivan", 2));
    list = addfront(list, newitem("Gosho", 3));
    list = addend(list, newitem("Petran", 4));

    printf("printing list\n");
    apply(list, printnv, "%s: %d, ");
    printf("\n");

    list = reverse_iter(list);

    printf("printing list\n");
    apply(list, printnv, "%s: %d, ");
    printf("\n");

    list = reverse_rec(list);

    printf("printing list\n");
    apply(list, printnv, "%s: %d, ");
    printf("\n");

    return 0;
}

Nameval *reverse_iter(Nameval *list)
{
    Nameval *prev = NULL;
    Nameval *next = NULL;
    Nameval *curr = list;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Nameval *reverse_rec(Nameval *list)
{
    if (list == NULL)
        return NULL;

    if (list->next == NULL)
        return list;

    Nameval *new = reverse_rec(list->next);
    list->next->next = list;
    list->next = NULL;
    return new;
}