#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strncpy2(char *t, char *s, int n);
int test(char *src, char *expected, int n);

int main()
{
    int res = 0;
    res += test("something", "somet", 5);
    res += test("something", "something", 9);
    res += test("something", "something", 100);
    res += test("something", "", 0);
    res += test("something", "", -1);
    res += test("", "", 10);
    res += test(NULL, "", 1);

    if (res != 0)
    {
        printf("❌ %d tests failed\n", res);
    }
    else
    {
        printf("✅ all tests passed\n");
    }

    return res;
}

int test(char *src, char *expected, int n)
{
    char *nn = (char *)malloc(100 * sizeof(char));
    strncpy2(nn, src, n);
    return strcmp(nn, expected) != 0;
}

void strncpy2(char *t, char *s, int n)
{
    if (t == NULL || s == NULL)
        return;
    while (n > 0 && *s != '\0')
    {
        *t = *s;
        t++;
        s++;
        n--;
    }
}