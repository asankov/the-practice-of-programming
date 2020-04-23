#include <stdio.h>
#include <stdlib.h>
#include "values.c"

void quicksort(int v[], int n);
void swap(int v[], int i, int j);

int main()
{
    quicksort(numbers, NELEMS(numbers));
    printf("sorted numbers:\n");
    for (int i = 0; i < NELEMS(numbers); i++)
    {
        printf("%d, ", numbers[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int v[], int n)
{
    int last = 0;
    if (n <= 1)
        return;

    swap(v, 0, rand() % n); /* move pivot to v[0] */
    for (int i = 0; i < n; i++)
        if (v[i] < v[0])
            swap(v, ++last, i);

    swap(v, 0, last);
    quicksort(v, last);
    quicksort(v + last + 1, n - last - 1);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}