# Chapter 5: Debugging

## Section 5.6 Debugging Tools

**Summary:** There are more debugging tools than a debugger.
One such would be a program that reads a compiled program and output its meaningful content.
This way if we are getting an error message, but don't know where that is comming from we can do:

```console
strings *.exe *.dll | grep 'some error message'
```

For the implementation, see [`strings.c`](strings.c)

### Exercise 5-2

The `strings` program prints strings with `MINLEN` or more characters, which sometimes produces more output than is useful.
Provide `strings` with an optional argument to define the minimum string length.

_Answer:_ Changed applied to [`strings.c`](strings.c) in [this commit](https://github.com/asankov/the-practice-of-programming/commit/4a99559bcb586c94036bc97107e21a9112c314b9).

### Exercise 5-3

Write `vis`, which copies input to output, except that it displays non-printable bytes like backspaces, control characters,
and non-ASCII characters as `\Xhh` where `hh` is the hexadecimal representaton of the non-printable byte.
By contrast with `strings`, `vis` is more useful for examining inputs that contain only a few non-printable characters.

_Answer:_ See [`vis.c`](vis.c) added in [this commit](https://github.com/asankov/the-practice-of-programming/commit/f81c7edac11980493af906a5a9bdb1900bf9a8cf).

### Exercise 5-4

What does `vis` produce if the input is `\XOA`? How could you make output of `vis` unambiguous?

_Answer_:

```console
$ gcc vis.c -o executable && ./executable xoa.txt

$ gcc vis.c -o executable && ./executable xoa.txt --minlen 1
xoa.txt:\XOA
```

It producec nothing, because the input is too short. If we set the min input to 1 (or something smaller that the actual output), then it outputs the text.

### Exercise 5-5

Extend `vis` to process a sequence of files, fold long lines at any desired column, and remove non-printable characters entirely.
What other features might be consistent with the role of the program?

_Answer:_

- process a sequence of files: See the changes to [`vis.c`](vis.c) added in [this commit](https://github.com/asankov/the-practice-of-programming/commit/4cbb1e96ef3805c376d777f2d4c3f005087f2f6c).
