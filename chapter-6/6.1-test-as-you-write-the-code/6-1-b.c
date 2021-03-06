#include <stdio.h>

void print(char *s);

int main()
{
    printf("Test 1:\n");
    print("hello");

    printf("Test 2:\n");
    char s[] = {};
    print(s);

    printf("Test 3:\n");
    print("\0");

    printf("Test 4:\n");
    print(NULL);

    return 0;
}

// 6-1.b This is supposed to print the characters of a string one per line.
void print(char *s)
{
    if (s == NULL)
        return;

    int i = 0;
    while (s[i] != '\0')
    {
        putchar(s[i++]);
        putchar('\n');
    }
}