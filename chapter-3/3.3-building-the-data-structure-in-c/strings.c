#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    STRINGS_SIZE = 1000,
    _MULTIPLIER = 37,
};

typedef struct String String;
struct String
{
    char *val;
    String *next;
};
String *words[STRINGS_SIZE];

int hash_string(char *val)
{
    int h = 0;
    for (unsigned char *p = (unsigned char *)val; *p != '\0'; p++)
        h = _MULTIPLIER * h + *p;

    return h % STRINGS_SIZE;
}

String *lookup_string(char *val, int create)
{
    int h = hash_string(val);
    for (String *s = words[h]; s != NULL; s = s->next)
        if (strcmp(s->val, val) == 0)
            return s;

    if (create)
    {
        String *s = (String *)malloc(sizeof(String));
        if (s == NULL)
            return NULL;
        s->val = val;
        s->next = words[h];
        words[h] = s;
        return s;
    }

    return NULL;
}