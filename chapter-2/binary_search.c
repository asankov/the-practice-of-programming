#include <stdio.h>
#include <strings.h>
#include "values.c"

int lookup(char *name, char *tab[], int ntab);

int main()
{
    int res = lookup("B", letters, NELEMS(letters));
    if (res != 1)
    {
        printf("ERROR: Got %d for `lookup(\"B\", letters, NELEMS(letters)), expected %d`\n", res, 1);
        return 1;
    }

    res = lookup("G", letters, NELEMS(letters));
    if (res != 6)
    {
        printf("ERROR: Got %d for `lookup(\"G\", letters, NELEMS(letters)), expected %d`\n", res, 6);
        return 1;
    }

    res = lookup("Q", letters, NELEMS(letters));
    if (res != -1)
    {
        printf("ERROR: Got %d for `lookup(\"Q\", letters, NELEMS(letters)), expected %d`\n", res, -1);
        return 1;
    }

    printf("SUCCESS.\n");
    return 0;
}

int lookup(char *name, char *tab[], int ntab)
{
    int low, high, mid, cmp;

    low = 0;
    high = ntab - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cmp = strcmp(name, tab[mid]);
        if (cmp < 0)
            high = mid - 1;
        else if (cmp > 0)
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}