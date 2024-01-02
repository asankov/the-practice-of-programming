# Chapter 1: Style

## 1.4 Function Macros

### Exercise 1-9

Identify the problem with this macro definition:

```c
#define ISDIGIT(c) ((c >= '0') && (c <= '9'>)) ? 1 : 0
```

_Answer:_
Problems:

- multiple evaluation - this macros uses its argument twice, which means that being passed a statement, that statement would be evaluated twice, hence possiblity for side effects. _Example:_

```c
int is_digit = ISDIGIT(getchar())
```

would be compiled to

```c
int is_digit = ((getchar() >= '0') && (getchar() <= '9'>)) ? 1 : 0
```

which will read two values, and will possibly yield wrong result.

- macro not wrapped in parentheses - which means that if used the wrong way it will evaluate in an unexpected way and the whole code will have different meaning. _Example:_

```c
int is_digit_or_letter = ISDIGIT(c) ? 1 : ISLETTER(c) ? 1 : 0
```

would be compiled as:

```c
int is_digit_or_letter = ((c >= '0') && (c <= '9'>)) ? 1 : 0 ? 1 : ISLETTER(c) ? 1 : 0
```

which could again yield unexpected result and lead to nasty bugs and hours of debugging.
