#include <stdio.h>

#include "hash_tables.c"

int main()
{
    char *urls[] = {
        "http://localhost",
        "http://localhost:8000",
        "http://localhost:8001",
        "http://localhost:8000/docs",
        "http://localhost:8001/docs",
        "https://localhost",
        "http://test.local/docs",
        "https://test.local/docs",
    };

    for (int i = 0; i < sizeof(urls)/sizeof(urls[0]); i++)
    {
        printf("%d\n", hash(urls[i]));
    }
}