## Chapter 1: Style

### 1.1 Names

### Exercise 1-1
Comment on the choice of names and values in the following code:
```c
#define TRUE 0
#define FALSE 1

if ((ch = getchar()) == EOF)
    not_eof = FALSE;
```

*Answer:* I think the naming here is all wrong, because:
- `TRUE` should be `1`, and `FALSE` should be `0`. Written as they are now, `while(FALSE){ /* code */ }` would result in an infinite loop
and `while(TRUE){ /* code */ }` would never be executed. This is misleading and would lead to someone spending hours debugging this problem.

For the second part, while the logic is true, the naming is weird and may lead to confussion. A much better version would be:
```c
if ((ch = getchar()) == EOF)
    eof = TRUE;
```
The other version may lead to double negation like `if (!not_eof) { /* code */ }` which is more confusing than the simple `if (eof) { /* code */}`.

### Exercise 1-2
Improve this function.
```c
int smaller(char *s, char *t) {
    if (strcmp(s, t) < 1)
        return 1;
    else
        return 0;
}
```

*Answer:*
```c
/* smaller_than: returns 1 if s is smaller than t, otherwise 0 */
int is_smaller_than(char *s, char *t) {
    if (strcmp(s, t) >= 0)
        return 0;
    return 1;
}
```
Improvements:
- naming - this way it is clear what the function does
- documentation - what is not clear from the name (which string is smaller that which) is clear by the doc string
- code - reversed the condition to fit the name and docs. This way the function is different than the original, but it does what it says

### Exercise 1-3
Read this code aloud.
```c
if ((falloc(SMRHHSHSCRTCH, S_IFEXT|0644, MAXRODDHSH)) < 0)
    ...
```
As hard as it was - done.