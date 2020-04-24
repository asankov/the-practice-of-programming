#include <stdio.h>

void swap(int *xp, int *yp);
void sort(int arr[], int n);

int main()
{
    int arr[] = {10, 12, 45, 38, 57, 12, 27, 129, 17, 27, 49, 48};
    sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}