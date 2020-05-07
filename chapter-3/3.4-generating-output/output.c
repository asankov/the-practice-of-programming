#include "../3.3-building-the-data-structure-in-c/structs.c"

void generate(int nwords)
{

    char *prefix[NPREF], *w;

    for (int i = 0; i < NPREF; i++) /* reset initial prefix */
        prefix[i] = NONWORD;

    for (int i = 0; i < nwords; i++)
    {
        State *sp = lookup(prefix, 0);
        int nmatch = 0;
        for (Suffix *suf = sp->suf; suf != NULL; suf = suf->next)
            if (rand() % ++nmatch == 0) /* probability: 1/nmatch */
                w = suf->word;
        if (strcmp(w, NONWORD) == 0)
            break;
        printf("%s ", w);
        memmove(prefix, prefix + 1, (NPREF - 1) * sizeof(prefix[0]));
        prefix[NPREF - 1] = w;
    }
}

void printt()
{
    printf("Input prefix \t\t\t Suffix words\n");
    for (int i = 0; i < NHASH; i++)
    {
        State *st = statetab[i];

        for (State *st = statetab[i]; st != NULL; st = st->next)
        {
            if (strcmp(st->pref[0], "\n") == 0 || strcmp(st->pref[1], "\n") == 0)
                continue;
            printf("%s %s \t\t\t", st->pref[0], st->pref[1]);
            for (Suffix *s = st->suf; s != NULL; s = s->next)
                printf("%s ", s->word);
            printf("\n");
        }
    }
}

int main(void)
{
    char *prefix[NPREF];

    for (int i = 0; i < NPREF; i++)
        prefix[i] = NONWORD;

    FILE *f = fopen("text.txt", "r");
    if (f == NULL)
        return 1;
    build(prefix, f);
    fclose(f);
    add(prefix, NONWORD);
    // printt();
    generate(MAXGEN);
    return 0;
}