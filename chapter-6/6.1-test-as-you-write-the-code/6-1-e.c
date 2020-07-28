#include <stdio.h>

void compare(int i, int j);

int main()
{
    compare(1, 2);
    compare(1, 0);
    compare(1, 1);
}

void compare(int i, int j)
{
    if (i > j)
        printf("%d is greater than %d.\n", i, j);
    else
        printf("%d is smaller than %d.\n", i, j);
}