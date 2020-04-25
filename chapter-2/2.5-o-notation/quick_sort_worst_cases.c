#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int icmp(const void *p1, const void *p2);
void cmp_arr(int first[], int second[], char *name);

int main()
{
    int random[] = {6, 4, 5, 9, 2, 7, 3, 1, 10, 8};
    int random_bigger[] = {6, 4, 5, 9, 2, 7, 3, 1, 10, 8, 6, 4, 5, 9, 2, 7, 3, 1, 10, 8};
    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_bigger[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int sorted_reverse[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sorted_reverse_bigger[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int all_equal[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int all_equal_bigger[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int all_equal_but_one[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 10};
    int all_equal_but_one_bigger[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10};
    int all_equal_but_one_reverse[] = {10, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int all_equal_but_one_reverse_bigger[] = {10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    cmp_arr(random, random_bigger, "random");
    cmp_arr(sorted, sorted_bigger, "sorted");
    cmp_arr(sorted_reverse, sorted_reverse_bigger, "sorted_reverse");
    cmp_arr(all_equal, all_equal_bigger, "all_equal");
    cmp_arr(all_equal_but_one, all_equal_but_one_bigger, "all_equal_but_one");
    cmp_arr(all_equal_but_one_reverse, all_equal_but_one_reverse_bigger, "all_equal_but_one_reverse");
}

void cmp_arr(int first[], int second[], char *name)
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    qsort(first, 10, sizeof(first[0]), icmp);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_first = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("time for sorting %s: %llu\n", name, delta_first);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    qsort(second, 20, sizeof(second[0]), icmp);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_second = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("time for sorting %s_bigger: %llu\n", name, delta_second);
    printf("for twice the more values, sorting %s array, the difference in iterations was %llu ms slower\n", name, delta_second - delta_first);
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