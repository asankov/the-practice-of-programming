# Chapter 1: Style

## 1.2 Expressions and Statemenents

### Exercise 1-4

Improve each of these fragments:

```c
if (!(c == 'y' || c == 'Y'))
    return;
```

```c
length = (length < BUFFSIZE) ? length : BUFFSIZE;
```

```c
flag = flag ? 0 : 1;
```

```c
quote = (*line == '"') ? 1 : 0;
```

```c
if (val & 1)
    bit = 1;
else
    bit = 0;
```

_Answer:_

```c
if (c != 'y' && c != 'Y')
    return;
```

Because this way reads more naturally.

```c
length = (length > BUFFSIZE) ? BUFFSIZE : length;
```

Because this way reads more naturally.

```c
flag = !flag;
```

This is simpler and obvious.

```c
is_quote = *line == '"';
```

This is simpler and obvious.

```c
bit = val & 1;
```

This is simpler and obvious.

### Exercise 1-5

What is wrong with this excerpt?

```c
int read(int *ip) {
    scanf("%d", ip);
    return *ip;
}
  ...
insert(&graph[vert], read(&val), read(&ch));
```

_Answer:_ The thing that is wrong with the `read` function is that it both scans the value into `ip` and returns the value.
This seems weird, and people may find clever ways to utilize this. As we know from the book - clear is better than clever.
The thing that is wrong with the call to `insert` comes from that problem with `read`. This statement does 3 things at the same time.
Calls `insert` with the value, read from stdin, and assigns them to `val` and `ch` respectively. This may lead to nasty bugs
and more hours of debugging.

### Exercise 1-6

List all the different outputs this could produce with various orders of evaluation:

```c
n = 1;
printf("%d %d\n", i++, i++);
```

_Answer:_ The possible outputs are:

- `1 1`
- `1 2`
- `2 2`
- `2 3`

However, in my opinion the most common one would be `1 2`, because the `++` operator has a good definition, and that is:
`increment the variable and return the old value`. So the first `i++` would increment `i`, but would return the old value of `i`, hence `1`.
The second call to `i++` would increment the variable again and return the old value, which is now `2`. If we try to use `i` one more time, the value would now be `3`.

For experimentation I created [eval.c](eval.c), which I compiled twice - with `gcc` and `clang` on MacOS.
The output of both compilations was identical - warning for multiple unsequenced moditification -

```text
eval.c:6:24: warning: multiple unsequenced modifications to 'n' [-Wunsequenced]
    printf("%d %d\n", n++, n++);
                       ^    ~~
1 warning generated.
```

and running both executables many times produced the same output always:

```text
1 2
```

In conclusion, while this code is bad, and must not be ran in production the output it produces is rather predictable and no surprises occurred while running it.
