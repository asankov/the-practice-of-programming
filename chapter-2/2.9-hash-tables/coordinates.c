#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x;
    float y;
} Coordinates;

int hash(Coordinates *coordinates, int size);

int main()
{
    Coordinates *c = malloc(sizeof(Coordinates));
    if (c == NULL)
        return 1;

    c->x = 5;
    c->y = 10;

    printf("%d\n", hash(c, 12));

    c->x = 15;
    c->y = 20;

    printf("%d\n", hash(c, 12));

    c->x = 50;
    c->y = 100;

    printf("%d\n", hash(c, 12));
    return 0;
}

int hash(Coordinates *coordinates, int size)
{
    int diff = coordinates->x - coordinates->y;
    if (diff < 0)
        diff = -diff;
    int sum = coordinates->x + coordinates->y;
    int h = (31 * coordinates->x) + (37 * coordinates->y) + (41 * diff) + (47 * sum);
    return h % size;
}