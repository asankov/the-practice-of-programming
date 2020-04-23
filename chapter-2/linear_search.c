#include <stdio.h>
#include <strings.h>

int lookup(char *word, char *array[]);

int main()
{
    char *flab[] = {
        "actually",
        "just",
        "quite",
        "really",
        NULL};

    int res = lookup("just", flab);
    if (res != 1)
    {
        printf("ERROR: Got %d for `lookup(\"just\", flab), expected %d`\n", res, 1);
        return 1;
    }

    res = lookup("not present", flab);
    if (res != -1)
    {
        printf("ERROR: Got %d for `lookup(\"not present\", flab), expected %d`\n", res, 1);
        return 1;
    }

    printf("SUCCESS.\n");
    return 0;
}

/* lookup: sequential search for word in an array */
int lookup(char *word, char *array[])
{
    for (int i = 0; array[i] != NULL; i++)
    {
        if (strcmp(word, array[i]) == 0)
            return i;
    }
    return -1;
}