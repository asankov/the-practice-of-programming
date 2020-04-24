/*
Exercise 2.1. Quicksort is most naturally expressed recursively. 
              Write it iteratatively and compare the two versions.
*/

#include <stdio.h>
#include <stdlib.h>
#include "values.c"

void swap(int v[], int i, int j);
void quicksort_rec(int v[], int n);
void quicksort_iter(int v[], int n);

int main()
{
    // make two copies of the numbers array
    int *numbers_rec = malloc(sizeof(numbers) * sizeof(numbers[0]));
    int *numbers_iter = malloc(sizeof(numbers) * sizeof(numbers[0]));
    if (numbers_rec == NULL || numbers_iter == NULL)
    {
        printf("error: cannot copy array content");
        return 1;
    }
    for (int i = 0; i < NELEMS(numbers); i++)
    {
        numbers_iter[i] = numbers[i];
        numbers_rec[i] = numbers[i];
    }

    quicksort_rec(numbers_rec, NELEMS(&numbers_rec));
    quicksort_iter(numbers_iter, NELEMS(&numbers_iter) - 1);

    for (int i = 0; i < NELEMS(numbers); i++)
    {
        if (numbers_iter[i] != numbers_rec[i])
        {
            printf("error: expected element of both arrays to be equal.");
            return 1;
        }
    }

    printf("SUCCESS.\n");
    return 0;
}

void quicksort_rec(int v[], int n)
{
    int last = 0;
    if (n <= 1)
        return;

    swap(v, 0, rand() % n); /* move pivot to v[0] */
    for (int i = 0; i < n; i++)
        if (v[i] < v[0])
            swap(v, ++last, i);

    swap(v, 0, last);
    quicksort_rec(v, last);
    quicksort_rec(v + last + 1, n - last - 1);
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, ++i, h);
    return i;
}

void quicksort_iter(int v[], int n)
{
    int l = 0;

    while (1)
    {
        int p = partition(v, l, n);

        // If there are elements on left side of pivot,
        // then sort the left side of the array
        if (p - 1 > l)
        {
            n = p - 1;
        }
        // else if there are elements on right side of pivot,
        // then sort the right side of the array
        else if (p + 1 < n)
        {
            l = p + 1;
        }
        // else the array is sorted and we have nothing more to do
        else
        {
            break;
        }
    }
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}