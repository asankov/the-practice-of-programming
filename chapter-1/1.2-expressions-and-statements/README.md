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