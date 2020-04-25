#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval
{
    char *name;
    int value;
} Nameval;

struct NVtab
{
    int nval;         /* current number of values */
    int max;          /* allocated number of values*/
    Nameval *nameval; /* array of name-value pairs*/
} nvtab;

enum
{
    NVINIT = 1,
    NVGROW = 2
};

int delname(char *name);
int delname_no_memmove(char *name);
int delname_marked(char *name);
int addname(Nameval newname);
int addname_marked(Nameval newname);
void print_nvtab();

int main()
{
    Nameval *n = (Nameval *)malloc(sizeof(Nameval));
    (*n).name = "Ivan";
    (*n).value = 1;
    addname(*n);

    (*n).name = "Georgi";
    (*n).value = 2;
    addname(*n);

    (*n).name = "Anton";
    (*n).value = 4;
    addname(*n);

    (*n).name = "Pesho";
    (*n).value = 4;
    addname(*n);

    (*n).name = "Dragan";
    (*n).value = 5;
    addname(*n);

    (*n).name = "Petkan";
    (*n).value = 6;
    addname(*n);

    print_nvtab();

    delname("Dragan");
    printf("after deleting Dragan\n");

    print_nvtab();

    delname("Dragan");
    delname_no_memmove("Petkan");
    printf("after deleting Petkan\n");

    print_nvtab();

    delname_marked("Georgi");
    (*n).name = "Gosho";
    (*n).value = 5;
    addname_marked(*n);

    printf("Gosho should be in second place, instead of Georgi\n");
    print_nvtab();

    return 0;
}

void print_nvtab()
{
    for (int i = 0; i < nvtab.nval; i++)
    {
        printf("%s-%d, ", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }
    printf("\n");
}

/* addname: add new name and value to nvtab */
int addname(Nameval newname)
{
    Nameval *nvp;

    if (nvtab.nameval == NULL) /* first time */
    {
        printf("initializing nvtab.nameval\n");
        nvtab.nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1; /* not enough memory to allocate */
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    }
    else if (nvtab.nval == nvtab.max) /* need to grow the array */
    {
        printf("growing nvtab.nameval - new size: %d\n", NVGROW * nvtab.max);
        nvp = (Nameval *)realloc(nvtab.nameval, (NVGROW * nvtab.max) * sizeof(Nameval));
        if (nvp == NULL)
            return -1; /* not enough memory to reallocate */
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }

    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

int delname(char *name)
{
    for (int i = 0; i < nvtab.nval; i++)
    {
        if (strcmp(nvtab.nameval[i].name, name) == 0)
        {
            memmove(nvtab.nameval + i, nvtab.nameval + i + 1, (nvtab.nval - (i + 1)) * sizeof(Nameval));
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}

int delname_no_memmove(char *name)
{
    for (int i = 0; i < nvtab.nval; i++)
    {
        if (strcmp(nvtab.nameval[i].name, name) == 0)
        {
            for (int j = i; j < nvtab.nval; j++)
            {
                nvtab.nameval[j] = nvtab.nameval[j + 1];
            }
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}

int addname_marked(Nameval newname)
{
    Nameval *nvp;

    if (nvtab.nameval == NULL) /* first time */
    {
        printf("initializing nvtab.nameval\n");
        nvtab.nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1; /* not enough memory to allocate */
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    }
    else
    {
        for (int i = 0; i < nvtab.nval; i++)
        {
            if (nvtab.nameval[i].name == NULL)
            {
                nvtab.nameval[i] = newname;
                return nvtab.nval++;
            }
        }
    }

    if (nvtab.nval == nvtab.max) /* need to grow the array */
    {
        printf("growing nvtab.nameval - new size: %d\n", NVGROW * nvtab.max);
        nvp = (Nameval *)realloc(nvtab.nameval, (NVGROW * nvtab.max) * sizeof(Nameval));
        if (nvp == NULL)
            return -1; /* not enough memory to reallocate */
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }

    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

int delname_marked(char *name)
{
    for (int i = 0; i < nvtab.nval; i++)
    {
        if (strcmp(nvtab.nameval[i].name, name) == 0)
        {
            nvtab.nameval[i].name = NULL;
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}
