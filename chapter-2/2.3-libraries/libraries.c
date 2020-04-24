#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "values.c"

void sort_numbers();
void sort_letters();
void binary_search();
int scmp(const void *p1, const void *p2);
int icmp(const void *p1, const void *p2);
int lookup(char *name, char *tab[], int ntab);

int main()
{
    sort_numbers();
    sort_letters();
    binary_search();

    return 0;
}

void sort_numbers()
{
    qsort(numbers, NELEMS(numbers), sizeof(numbers[0]), icmp);
    printf("sorted numbers:\n");
    for (int i = 0; i < NELEMS(numbers); i++)
    {
        printf("%d, ", numbers[i]);
    }
    printf("\n");
}

void sort_letters()
{
    qsort(letters, NELEMS(letters), sizeof(letters[0]), scmp);
    printf("sorted letters:\n");
    for (int i = 0; i < NELEMS(letters); i++)
    {
        printf("%s, ", letters[i]);
    }
    printf("\n");
}

void binary_search()
{
    int res = lookup("B", letters, NELEMS(letters));
    if (res != 1)
    {
        printf("ERROR: Got %d for `lookup(\"B\", letters, NELEMS(letters)), expected %d`\n", res, 1);
        return;
    }

    res = lookup("G", letters, NELEMS(letters));
    if (res != 6)
    {
        printf("ERROR: Got %d for `lookup(\"G\", letters, NELEMS(letters)), expected %d`\n", res, 6);
        return;
    }

    res = lookup("Q", letters, NELEMS(letters));
    if (res != -1)
    {
        printf("ERROR: Got %d for `lookup(\"Q\", letters, NELEMS(letters)), expected %d`\n", res, -1);
        return;
    }

    printf("binary search: success\n");
}

/* lookup: use binary search el in tab*/
int lookup(char *el, char *tab[], int ntab)
{
    char **res = (char **)bsearch(&el, tab, ntab, sizeof(tab[0]), scmp);
    if (res == NULL)
        return -1;
    else
        return res - tab;
}

int scmp(const void *p1, const void *p2)
{
    char *v1 = *(char **)p1;
    char *v2 = *(char **)p2;

    return strcmp(v1, v2);
}

int icmp(const void *p1, const void *p2)
{
    int v1 = *(int *)p1;
    int v2 = *(int *)p2;

    if (v1 > v2)
        return 1;
    else if (v2 > v1)
        return -1;
    else
        return 0;
}