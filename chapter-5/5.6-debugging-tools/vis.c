#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 10000

int min_len = 6;

void vis(char *name, FILE *fn);

int main(int argc, char *argv[])
{
    int i;
    FILE *fn;

    if (argc == 1 || argc == 3) {
        printf("usage: strings filename [--minlen minlen]");
        return -1;
    }

    if (argc == 4) {
        min_len = atoi(argv[3]);
    }

    char *filename = argv[1];
    if ((fn = fopen(filename, "rb")) == NULL) {
        printf("can't open %s", filename);
        return -1;
    }
    vis(filename, fn);
    fclose(fn);

    return 0;
}

void vis(char *name, FILE *fn)
{
    int c, i;
    char buf[BUFSIZE];

    do {
        for (i = 0; (c=getc(fn)) != EOF;)
        {
            if (!isprint(c)) {
                sprintf(&buf[i++], "\\");
                sprintf(&buf[i++], "X");
                char s[3];
                sprintf(s, "%02x", c);
                sprintf(&buf[i++], "%c", s[0]);
                sprintf(&buf[i++], "%c", s[1]);
                continue;
            }

            buf[i++] = c;
            if (i >= BUFSIZE)
                break;
        }
        if (i >= min_len)
            printf("%s:%.*s\n", name, i, buf);
    } while (c != EOF);
}
