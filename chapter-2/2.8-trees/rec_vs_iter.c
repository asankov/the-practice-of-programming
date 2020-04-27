#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "trees.c"

typedef struct
{
    __darwin_time_t tv_sec;
    long tv_nsec;
} timespec;

timespec *time_lookup(Nameval *treep, char *name);
timespec *time_nrlookup(Nameval *treep, char *name);

int main()
{
    Nameval *treep = NULL;
    treep = insert(treep, newleaf("Item", 0));
    treep = insert(treep, newleaf("Item2", 0));
    treep = insert(treep, newleaf("Item3", 0));
    treep = insert(treep, newleaf("Item4", 0));
    treep = insert(treep, newleaf("Item5", 0));
    treep = insert(treep, newleaf("Item6", 0));
    treep = insert(treep, newleaf("Item7", 0));
    treep = insert(treep, newleaf("Item8", 0));
    treep = insert(treep, newleaf("Item9", 0));
    treep = insert(treep, newleaf("Item10", 0));
    treep = insert(treep, newleaf("Item11", 0));
    treep = insert(treep, newleaf("Item12", 0));
    treep = insert(treep, newleaf("Item13", 0));
    treep = insert(treep, newleaf("Item14", 0));

    char *name = "Item14";

    timespec *rec_time = time_lookup(treep, name);
    timespec *iter_time = time_nrlookup(treep, name);

    if (rec_time->tv_sec == 0 && iter_time->tv_sec == 0 && rec_time->tv_nsec == 0 && iter_time->tv_nsec == 0)
    {
        printf("Cannot measure the execution time precisely enough.");
        return 1;
    }

    if (rec_time->tv_sec == iter_time->tv_sec)
    {
        if (rec_time->tv_nsec > iter_time->tv_nsec)
        {
            printf("Iterative function is faster.\n");
        }
        else if (rec_time->tv_nsec < iter_time->tv_nsec)
        {
            printf("Recursive function is faster.\n");
        }
        else
        {
            printf("Both function ran for the same time.\n");
        }
    }
    else if (rec_time->tv_sec > iter_time->tv_sec)
    {
        printf("Iterative function is faster.\n");
    }
    else if (rec_time->tv_nsec < iter_time->tv_nsec)
    {
        printf("Recursive function is faster.\n");
    }

    printf("Iterative function took %lu s, %lu ns\n", iter_time->tv_sec, iter_time->tv_nsec);
    printf("Recursive function took %lu s, %lu ns\n", rec_time->tv_sec, rec_time->tv_nsec);

    return 0;
}

timespec *time_lookup(Nameval *treep, char *name)
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    lookup(treep, name);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    timespec *tt = (timespec *)malloc(sizeof(timespec));
    tt->tv_sec = (end.tv_sec - start.tv_sec);
    tt->tv_nsec = (end.tv_nsec - start.tv_nsec);

    return tt;
}

timespec *time_nrlookup(Nameval *treep, char *name)
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    nrlookup(treep, name);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    timespec *tt = (timespec *)malloc(sizeof(timespec));
    tt->tv_sec = (end.tv_sec - start.tv_sec);
    tt->tv_nsec = (end.tv_nsec - start.tv_nsec);

    return tt;
}