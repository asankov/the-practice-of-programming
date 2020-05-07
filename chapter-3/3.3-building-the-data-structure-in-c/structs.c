#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    NPREF = 2,       /* number of prefix words */
    NHASH = 4093,    /* size of state hash table array */
    MAXGEN = 10000,  /* maximum words generated */
    MULTIPLIER = 31, /* prime number to be used for hash computations */
};

char *NONWORD = "\n"; /* to be used as terminating sequence flag */

typedef struct State State;
typedef struct Suffix Suffix;
struct State /* prefix + suffix list*/
{
    char *pref[NPREF]; /* prefix words */
    Suffix *suf;       /* list of suffixes */
    State *next;       /* next in hash table */
};
State *statetab[NHASH];

struct Suffix /* list of suffixes */
{
    char *word;   /* suffix */
    Suffix *next; /* next in list of suffixes */
};

/* hash: computer hash value for array of NPREF strings */
unsigned int hash(char *s[NPREF])
{
    unsigned int h = 0;

    for (int i = 0; i < NPREF; i++)
        for (unsigned char *p = (unsigned char *)s[i]; *p != '\0'; p++)
            h = MULTIPLIER * h + *p;
    return h % NHASH;
}

State *lookup(char *prefix[NPREF], int create)
{
    int i;
    int h = hash(prefix);

    for (State *sp = statetab[h]; sp != NULL; sp = sp->next)
    {
        for (i = 0; i < NPREF; i++)
            if (strcmp(prefix[i], sp->pref[i]) != 0)
                break;
        // TODO: is that check needed, maybe we can return directly here
        if (i == NPREF) /* found it */
            return sp;
    }

    if (create)
    {
        State *sp = (State *)malloc(sizeof(State));
        if (sp == NULL) /* not enough memory to allocate for *sp */
            return NULL;
        for (int i = 0; i < NPREF; i++)
            sp->pref[i] = prefix[i];
        sp->suf = NULL;
        sp->next = statetab[h];
        statetab[h] = sp;
        return sp;
    }

    /* not found and create not set */
    return NULL;
}

/* addsuffix: add to state */
void addsuffix(State *sp, char *suffix)
{
    Suffix *suff = (Suffix *)malloc(sizeof(Suffix));
    if (suff == NULL)
        return;
    suff->word = suffix;
    suff->next = sp->suf;
    sp->suf = suff;
}

/* add: add suffix to suffix list, update prefix */
void add(char *prefix[NPREF], char *suffix)
{
    State *sp = lookup(prefix, 1);
    addsuffix(sp, suffix);
    memmove(prefix, prefix + 1, (NPREF - 1) * sizeof(prefix[0]));
    prefix[NPREF - 1] = suffix;
}

/* build: read input, build prefix table*/
void build(char *prefix[NPREF], FILE *f)
{
    char buf[100], fmt[10];

    /* a call to fscanf will read until whitespace, which may overflow buffer. 
    that is why we are building a format string that is equal to '%99s',
    so that we tell fscaf to stop after the 99th byte (leaving one bute for '\0')*/
    sprintf(fmt, "%%%lus", sizeof(buf) - 1);
    while (fscanf(f, fmt, buf) != EOF)
        add(prefix, strdup(buf));
}
