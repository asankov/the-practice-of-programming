#include <stdio.h>
#include <string.h>

char buf[200];   /* input line buffer */
char *field[20]; /* fields */

/* unquote: remove leading and trailing quote */
char *unquote(char *p)
{
    if (p[0] == '"')
    {
        if (p[strlen(p) - 1] == '"')
            p[strlen(p) - 1] = '\0';
        p++;
    }
    return p;
}

/* csvgetline: read and parse line, return field count */
/* samle input: "LU",86.25, "11/4/1998","2:19PM",+4.0625 */
int csvgetline(FILE *fn)
{
    char *p;

    if (fgets(buf, sizeof(buf), fn) == NULL)
        return -1;
    int nfield = 0;
    for (char *q = buf; (p = strtok(q, ",\n\r")) != NULL; q = NULL)
        field[nfield++] = unquote(p);
    return nfield;
}

int main(void)
{
    int nf;

    while ((nf = csvgetline(stdin)) != -1)
        for (int i = 0; i < nf; i++)
            printf("field[%d] = '%s'\n", i, field[i]);
    return 0;
}