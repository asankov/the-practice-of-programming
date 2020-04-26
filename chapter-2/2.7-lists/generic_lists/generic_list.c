#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    void *object;
    void **next;
} List;

typedef struct
{
    char *name;
    int age;
} Person;

int main()
{
    List *ll = (List *)malloc(sizeof(List));
    if (ll == NULL)
    {
        printf("Not enought memory to allocate for the list.");
        return 1;
    }

    Person *p = (Person *)malloc(sizeof(Person));
    if (p == NULL)
    {
        printf("Not enough memory to allocate for the person.");
        return 1;
    }

    p->name = "Peter";
    p->age = 21;

    ll->object = p;
    ll->next = NULL;

    p = (Person *)malloc(sizeof(Person));
    if (p == NULL)
    {
        printf("Not enough memory to allocate for the person.");
        return 1;
    }
    p->name = "Georgi";
    p->age = 22;

    List *new = (List *)malloc(sizeof(List));
    if (new == NULL)
    {
        printf("Not enought memory to allocate for the list.");
        return 1;
    }
    new->object = p;
    new->next = NULL;

    ll->next = new;

    for (; ll != NULL; ll = ll->next)
    {
        printf("%s: %d, ", ((Person *)ll->object)->name, ((Person *)ll->object)->age);
    }
    printf("\n");

    return 0;
}