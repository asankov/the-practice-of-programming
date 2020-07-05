#include <stdio.h>
#include <ctype.h>

#define MINLEN 6
#define BUFSIZE 10000

void strings(char *name, FILE *fn);

int main(int argc, char *argv[])
{
    int i;
    FILE *fn;

    if (argc == 1) {
        printf("usage: strings filename");
        return -1;
    }

    for (i = 1; i < argc; i++)
    {
        if ((fn = fopen(argv[i], "rb")) == NULL) {
            printf("can't open %s", argv[i]);
            return -1;
        }
        strings(argv[i], fn);
        fclose(fn);
    }

    return 0;
}

void strings(char *name, FILE *fn)
{
    int c, i;
    char buf[BUFSIZE];

    do {
        for (i = 0; (c=getc(fn)) != EOF;)
        {
            if (!isprint(c))
                break;

            buf[i++] = c;
            if (i >= BUFSIZE)
                break;
        }
        if (i >= MINLEN)
            printf("%s:%.*s\n", name, i, buf);
    } while (c != EOF);
}
