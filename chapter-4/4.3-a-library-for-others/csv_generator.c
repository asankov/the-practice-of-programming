#include <stdio.h>
#include <stdlib.h>

void generate_csv(FILE *fn)
{
    int i, size = 100;
    char *word = NULL;

    while (1)
    {
        int c = fgetc(fn);

        if (word == NULL)
        {
            word = (char *)malloc(size * sizeof(char));
        }
        if (i > size)
        {
            size *= 2;
            word = (char *)realloc(word, size * sizeof(char));
        }

        if (c == ' ')
        {
            printf("%s, ", word);
            for (int j = 0; j < i; j++)
                word[j] = ' ';
            i = 0;
        }
        else if (c == EOF)
        {
            printf("%s\n", word);
            break;
        }
        else
        {
            word[i] = c;
            i++;
        }
    }
}

int main(void)
{
    generate_csv(stdin);

    return 0;
}