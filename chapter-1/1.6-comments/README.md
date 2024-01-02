# Chapter 1: Style

## 1.6 Comments

**Summary:** Comment should clarify, not confuse. They should agree with the code, not contradict it. They should describe why, not how, and should not repeat the code. They should not be everywhere, just where this clarifications are needed.

### Exercise 1-11

Comment on these comments _(answers inline)_:

```c
void dict::insert(string& w)
// returns 1 if w in dictionary, otherwise returns 0
```

This comment is obvious wrong and should be deleted. While it is possible for an `insert` method on `dict` to return a result, based on the presence of the inserted value, the code obviously shows that this function is `void`, hence it returns no result.

```c
if (n > MAX || n % 2 > 0) // test for even number
```

Here the comment is fully wrong. First, the code is for odd number, not even. Second, there is one more check - if `n` is bigger than `MAX`, which is not docummented. In my opinion, this comment should be deleted, because it is very obvious what's going on from the code itself.

```c
// Write a message
// Add to line counter for each line written

void write_message()
{
    // increment line counter
    line_number = line_number + 1;
    fprintf(fout, "%d %s\n%d %s\n%d %s\n",
        line_number, HEADER,
        line_number + 1, BODY,
        line_number + 2, TRAILER);
    // increment line counter
    line_number = line_number + 2;
}
```

Starting with the first comment -

```c
// Write a message
```

this is not wrong, but is the same as the method name, so it is obsolete.
A better comment would be

```c
// Write a meesage to fout
```

or no comment at all.

```c
// Add to line counter for each line written
```

This is misleading, because it does not tell how much it is added to the line counter.
A better and more description comment would be:

```c
// Increments line_number with 3
```

Onto the next comments:

- the first `// increment line counter` is obsolete, because that is evident from the code.
- the second `// increment line counter` is downright wrong, because the value of `line_number` is increased with `2`,
  while `increment` implies increase by 1 (or at least that is the most common user of the term).
