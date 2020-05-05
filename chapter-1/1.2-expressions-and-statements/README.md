## Chapter 1: Style

### 1.2 Expressions and Statemenents

#### Exercise 1-4
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
*Answer:*
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

#### Exercise 1-5
What is wrong with this excerpt?
```c
int read(int *ip) {
    scanf("%d", ip);
    return *ip;
}
  ...
insert(&graph[vert], read(&val), read(&ch));
```
*Answer:* The thing that is wrong with the `read` function is that it both scans the value into `ip` and returns the value.
This seems weird, and people may find clever ways to utilize this. As we know from the book - clear is better than clever.
The thing that is wrong with the call to `insert` comes from that problem with `read`. This statement does 3 things at the same time.
Calls `insert` with the value, read from stdin, and assigns them to `val` and `ch` respectively. This may lead to nasty bugs
and more hours of debugging.
