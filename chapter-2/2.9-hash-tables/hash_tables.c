#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    NHASH = 16,
    MULTIPLIER = 31
};

typedef struct Nameval Nameval;
struct Nameval
{
    char *name;
    int value;
    Nameval *next;
};

Nameval *symtab[NHASH];

void print_table();
unsigned int hash(char *str);
Nameval *lookup(char *name, int value, int create);

unsigned int hash(char *str)
{
    unsigned int h = 0;
    unsigned char *p;

    for (p = (unsigned char *)str; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    return h % NHASH;
}

/* lookup: find name in symtab, with optional create*/
Nameval *lookup(char *name, int value, int create)
{
    Nameval *sym;
    int h = hash(name);
    for (sym = symtab[h]; sym != NULL; sym = sym->next)
        if (strcmp(sym->name, name) == 0)
            return sym;

    if (create)
    {
        sym = (Nameval *)malloc(sizeof(Nameval));
        if (sym == NULL)
            return NULL;
        sym->name = name;
        sym->value = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

void print_table()
{
    for (int i = 0; i < NHASH; i++)
    {
        Nameval *sym = symtab[i];
        if (sym == NULL)
            continue; /* don't print the bucket if it does not have anything in it */

        printf("symtab[%d] = ", i);
        while (sym != NULL)
        {
            printf("(%s: %d) -> ", sym->name, sym->value);
            sym = sym->next;
        }
        printf("NULL\n");
    }
}