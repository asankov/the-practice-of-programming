#include <stdio.h>
#include <string.h>

#include "hash_tables.c"

int count(Nameval **map, int size);
void print_table_s(Nameval **table, int size, int print_null);
unsigned int hash_s(char *str);
void resize_map(Nameval **map, int factor);
void insert(Nameval **map, char *name, int value, int hash);
Nameval *lookup_rear(Nameval **arr, char *name, int value, int create, int x, int y);

int size = 10;
int main()
{
    Nameval **arr = malloc(sizeof(Nameval) * size);

    for (int i = 0; i < 42; i++)
    {
        char *name = (char *)malloc(sizeof(char) * 15);
        sprintf(name, "Name %d", i);
        lookup_rear(arr, name, 12, 1, 2, 2);
    }

    print_table_s(arr, size, 1);
}

/* lookup: find name in map, with optional create. 
   If the avarage array length is more than x, grow the table by y and rebuild it */
Nameval *lookup_rear(Nameval **map, char *name, int value, int create, int x, int y)
{
    /* search for name in map */
    Nameval *sym;
    int h = hash(name);
    for (sym = map[h]; sym != NULL; sym = sym->next)
        if (strcmp(sym->name, name) == 0)
            return sym;

    /* if create flag is set and name not in map, add name, value to map */
    if (create)
    {
        insert(map, name, value, h);
    }

    float av_length = count(map, size) / (float)size;

    /* resize tha map if average length more than x */
    if (av_length > x)
    {
        int j = 0;
        Nameval **new_arr = malloc(sizeof(Nameval) * size);
        for (int i = 0; i < size; i++)
            for (Nameval *a = map[i]; a != NULL; a = a->next)
                new_arr[j++] = a;

        for (int i = 0; i < size; i++)
            map[i] = NULL;

        int old_size = size;
        size = size * y;
        map = realloc(map, sizeof(Nameval) * size);
        for (int i = 0; i < old_size; i++)
        {
            int h = hash_s(new_arr[i]->name);
            insert(map, new_arr[i]->name, new_arr[i]->value, h);
        }
    }

    return sym;
}

unsigned int hash_s(char *str)
{
    unsigned int h = 0;
    unsigned char *p;

    for (p = (unsigned char *)str; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    return h % size;
}

int count(Nameval **map, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        for (Nameval *arr = map[i]; arr != NULL; arr = arr->next)
            sum++;
    return sum;
}

void insert(Nameval **map, char *name, int value, int hash)
{
    Nameval *sym = (Nameval *)malloc(sizeof(Nameval));
    if (sym == NULL)
        return;
    sym->name = name;
    sym->value = value;
    sym->next = map[hash];
    map[hash] = sym;
}

void print_table_s(Nameval **table, int size, int print_null)
{
    for (int i = 0; i < size; i++)
    {
        Nameval *sym = table[i];
        if (sym == NULL && !print_null)
            continue; /* don't print the bucket if it does not have anything in it */
        printf("table[%d] = ", i);
        while (sym != NULL)
        {
            printf("(%s: %d) -> ", sym->name, sym->value);
            sym = sym->next;
        }
        printf("NULL\n");
    }
}