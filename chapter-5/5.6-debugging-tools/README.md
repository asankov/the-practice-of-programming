# Chapter 5: Debugging

## Section 5.6 Debugging Tools
**Summary:** There are more debugging tools than a debugger.
One such would be a program that reads a compiled program and output its meaningful content.
This way if we are getting an error message, but don't know where that is comming from we can do:
```
$ strings *.exe *.dll | grep 'some error message'
```
For the implementation, see [`strings.c`](strings.c)

### Exercise 5-2
The `strings` program prints strings with `MINLEN` or more characters, which sometimes produces more output than is useful.
Provide `strings` with an optional argument to define the minimum string length.

### Exercise 5-3
Write `vis`, which copies input to output, except that it displays non-printable bytes like backspaces, control characters,
and non-ASCII characters as `\Xhh` where `hh` is the hexadecimal representaton of the non-printable byte.
By contrast with `strings`, `vis` is more useful for examining inputs that contain only a few non-printable characters.

### Exercise 5-4
What does `vis` produce if the input is `\XOA`? How could you make output of `vis` unambiguous?

### Exercise 5-5
Extend `vis` to process a sequence of files, fold long lines at any desired column, and remove non-printable characters entirely.
What other features might be consistent with the role of the program?