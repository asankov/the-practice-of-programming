#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(char *src);
void strcpy2(char *dest, char *src);

int main()
{
    int res = 0;
    res += test("");
    res += test(NULL);
    res += test("something");

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

int test(char *src)
{
    if (src == NULL)
        return 0;

    char *n = (char *)malloc(100 * sizeof(char));
    strcpy2(n, src);
    return strcmp(n, src) != 0;
}

void strcpy2(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
}