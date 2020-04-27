#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct Nameval Nameval;
struct Nameval
{
    char *name;
    int value;
    Nameval *next;
};

void freeall(Nameval *listp);
Nameval *copy(Nameval *listp);
void printnv(Nameval *p, void *arg);
Nameval *newitem(char *name, int value);
void incounter(Nameval *listp, void *arg);
Nameval *lookup(Nameval *listp, char *name);
void delitem(Nameval *listp, char *name);
Nameval *merge(Nameval *list, Nameval *other);
Nameval *addend(Nameval *listp, Nameval *newp);
Nameval *addfront(Nameval *listp, Nameval *newp);
int insert_after(Nameval *list, char *name, Nameval *newelem);
int insert_before(Nameval *list, char *name, Nameval *newelem);
void apply(Nameval *listp, void (*fn)(Nameval *, void *), void *arg);

void apply(Nameval *listp, void (*fn)(Nameval *, void *), void *arg)
{
    for (; listp != NULL; listp = listp->next)
        (*fn)(listp, arg);
}

/* newitem: create new Nameval with name and value and return it */
Nameval *newitem(char *name, int value)
{
    Nameval *newp = (Nameval *)malloc(sizeof(Nameval));
    if (newp == NULL)
        return NULL;

    newp->name = name;
    newp->value = value;
    newp->next = NULL;

    return newp;
}

/* addfront: add newp to the front of listp */
Nameval *addfront(Nameval *listp, Nameval *newp)
{
    newp->next = listp;
    return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp)
{
    if (listp == NULL)
        return newp;

    Nameval *p;
    for (p = listp; p->next != NULL; p = p->next)
        ; /* do nothing, just go to the end of the list */
    p->next = newp;
    return listp;
}

Nameval *lookup(Nameval *listp, char *name)
{
    while (listp != NULL)
    {
        if (strcmp(listp->name, name) == 0)
        {
            return listp;
        }
        listp = listp->next;
    }
    return NULL; /* no mathc found */
}

void delitem(Nameval *listp, char *name)
{
    Nameval *prev = NULL;
    for (Nameval *p = listp; p != NULL; p = p->next)
    {
        if (strcmp(p->name, name) == 0)
        {
            if (prev == NULL)
                listp = p->next;
            else
                listp->next = p->next;
            free(p);
            return;
        }
        prev = p;
    }
    printf("element not found in list");
}

/* freeall: destroy the list */
void freeall(Nameval *listp)
{
    Nameval *next;
    for (; listp != NULL; listp = next)
    {
        next = listp->next;
        /* assumes name is freed elsewhere */
        free(listp);
    }
}

/* copy: copies the elements of listp into a new list, without modifying the original list
    returns: the beginning of the new list
*/
Nameval *copy(Nameval *listp)
{
    Nameval *begin = NULL;

    for (; listp != NULL; listp = listp->next)
    {
        Nameval *new = (Nameval *)malloc(sizeof(Nameval));
        if (new == NULL)
            return NULL; /* not enough memory to allocate new element*/

        begin = addend(begin, newitem(listp->name, listp->value));
    }

    return begin;
}

/* merge: returns a new list that contains all elements from list and other, without modifying the original lists */
Nameval *merge(Nameval *list, Nameval *other)
{
    return addend(copy(list), copy(other));
}

int insert_before(Nameval *list, char *name, Nameval *newelem)
{
    Nameval *prev = NULL;

    for (; list != NULL; list = list->next)
    {
        if (strcmp(list->name, name) == 0)
        {
            if (prev == NULL) /* this means the matching element is the first one */
            {
                newelem->next = copy(list);
                *list = *newelem;
                return 1;
            }

            newelem->next = prev->next;
            prev->next = newelem;
            return 1;
        }
        prev = list;
    }

    return 0;
}

/* insert_after: it finds the elemenent with name=name in list and inserts newelem after that */
int insert_after(Nameval *list, char *name, Nameval *newelem)
{
    for (; list != NULL; list = list->next)
    {
        if (strcmp(list->name, name) == 0)
        {
            newelem->next = list->next;
            list->next = newelem;
            return 1;
        }
    }
    return 0;
}

void incounter(Nameval *listp, void *arg)
{
    /* listp is unused */
    int *ip = (int *)arg;
    (*ip)++;
}

void printnv(Nameval *p, void *arg)
{
    char *fmt = (char *)arg;
    printf(fmt, p->name, p->value);
}