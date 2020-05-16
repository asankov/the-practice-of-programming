/* csv.h: interface for csv library */

#include <stdio.h>

extern char *csvgetline(FILE *f, char *separator); /* read next input line */
extern char *csvfield(int n);                      /* return field n */
extern int csvnfield(void);                        /* return number of fields */
extern void init(int maxfield, int maxline);       /* initialize the library with proper starting values */