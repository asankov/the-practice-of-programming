#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    NOMEM = -2 /* out of memory signal */
};

static char *line = NULL;   /* input chars */
static char *sline = NULL;  /* line copy used by split */
static int maxline = 0;     /* size of line[] and sline[] */
static char **field = NULL; /* field pointers */
static int maxfield = 0;    /* size of fields[] */
static int nfield = 0;      /* number of fields in field[] */

static char fieldsep[] = ","; /* field separator chars*/

/* reset: set variables back to starting values */
static void reset(void)
{
    free(line);
    free(sline);
    free(field);
    line = NULL;
    sline = NULL;
    field = NULL;
    maxline = maxfield = nfield = 0;
}

/* endofline: check for and consume \r, \n, \r\n, or EOF */
static int endofline(FILE *fn, int c)
{
    int eol = (c == '\r' || c == '\n');

    if (c == '\r')
    {
        c = getc(fn);
        if (c != '\n' && c != EOF)
            ungetc(c, fn); /* read too far; put c back */
    }
    return eol;
}

/* advquoted: quoted field: return pointer to next separator*/
static char *advquoted(char *p)
{
    int i, j;

    for (i = j = 0; p[j] != '\0'; i++, j++)
    {
        if (p[j] == '"' && p[++j] != '"')
        {
            int k = strcspn(p + j, fieldsep);
            memmove(p + i, p + j, k);
            i += k;
            j += k;
            break;
        }
        p[i] = p[j];
    }
    p[i] = '\0';
    return p + j;
}

/* csvfield: return pointer to n-th field */
char *csvfield(int n)
{
    if (n < 0 || n >= nfield)
        return NULL;
    return field[n];
}

/* csvnfield: return number of fields */
int csvnfield(void)
{
    return nfield;
}

/* split: split line into fields */
static int split(void)
{
    char *sepp; /* pointer to temporary character */
    int sepc;

    nfield = 0;
    if (line[0] == '\0')
        return 0;
    strcpy(sline, line);
    char *p = sline;

    do
    {
        if (nfield >= maxfield)
        {
            maxfield *= 2; /* double character size */
            char **newf = (char **)realloc(field, maxfield * sizeof(field[0]));
            if (newf == NULL)
                return NOMEM;
            field = newf;
        }
        if (*p == '"')
            sepp = advquoted(++p); /* skip initial quote */
        else
            sepp = p + strspn(p, fieldsep);
        sepc = sepp[0];
        sepp[0] = '\0'; /* terminate field */
        field[nfield++] = p;
        p = sepp + 1;
    } while (sepc == ',');

    return nfield;
}

/* csvgetline: get one line, grow as needed */
/* sample input: "LU",86.25,"11/4/1998","2:19PM",+4.0625 */
char *csvgetline(FILE *fn)
{
    int c, i;
    char *newl, *news;

    if (line == NULL)
    {
        maxline = maxfield = 1; /* allocate on first call */
        line = (char *)malloc(maxline);
        sline = (char *)malloc(maxline);
        field = (char **)malloc(maxfield * sizeof(field[0]));
        if (line == NULL || sline == NULL || field == NULL)
        {
            reset();
            return NULL; /* out of memory */
        }
    }
    for (i = 0; (c = getc(fn)) != EOF && !endofline(fn, c); i++)
    {
        if (i >= maxline - 1) /* grow line */
        {
            maxline *= 2;
            newl = (char *)realloc(line, maxline);
            news = (char *)realloc(sline, maxline);
            if (newl == NULL || news == NULL)
            {
                reset();
                return NULL; /* out of memory */
            }
            line = newl;
            sline = news;
        }
        line[i] = c;
    }
    line[i] = '\0';
    if (split() == NOMEM)
    {
        reset();
        return NULL; /* out of memory */
    }
    return (c == EOF && i == 0) ? NULL : line;
}

int main(void)
{
    char *line;

    while ((line = csvgetline(stdin)) != NULL)
    {
        printf("line = '%s'\n", line);
        for (int i = 0; i < csvnfield(); i++)
            printf("field[%d] = '%s'\n", i, csvfield(i));
    }

    return 0;
}