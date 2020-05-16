/* csv.h: interface for csv library */

#include <stdio.h>

extern char *csvgetline(FILE *f, char *separator); /* read next input line */
extern char *csvfield(int n);                      /* return field n */
extern int csvnfield(void);                        /* return number of fields */
