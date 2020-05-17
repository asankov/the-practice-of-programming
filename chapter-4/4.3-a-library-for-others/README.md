## Chapter 4: Interfaces

### Section 4.3 A Library For Others
**Summary:** In this chapter we will build on the knowledge we gained writing the prototype and will build a full-fledged
library to be used by others.

The library consists of a [header file](csv.h), where the interfaces lives
and a [source file](csv.c), where the implementation lives. The consumers of the library will import the header file,
which will reference the compiled implementation.

#### Exercise 4-1
There are several degrees of laziness for field-splitting: among the possibilities are to split all
at once but only when some field is requsted, to split only the field requested, or to split up to
the field requested. Enumerate possibilities, assess their potential difficulty and benefits,
then write and measure their speeds.

*Answer:* Possibilities:
- split all at once but only when some field is requsted 
    - this is easy. the only thing that is gonna change in the code is the place, where `split` is called.
    This is going to be the first invocation of `csvfield`
- split only the field requested
    - here we need to count the delimeters and split only after counting up to N delimeters. 
- split up to the field requested
    - this will be easier than the second, because we start spliting one by one, and count how much we've splitted.

TODO: implementations #5

#### Exercise 4-2
Add a facility so separators can be changed 
(a) to an arbitrary class of characters;
(b) to different separators for different fields;
(c) to a regular expressions (see Chapter 9).
What should the interface look like?

*Answer:* For each of these the interface would change to something like
```c
char *csvgetline(FILE *f, char *separator);
```

*Implementation:* See this [commit](https://github.com/asankov/the-practice-of-programming/commit/a17b9876cd918e988d383993ee0a4003d958da4b).

#### Exercise 4-3
WE chose to use the static initialization provided by C as the basis of a one-time switch: 
if a pointer is NULL on entry, initialization is performed. Another possibility is to required the user to call an explicit
initialization function, which could include suggested initial sizes for arrays.
Implement a version that combines the best of both. What is the role of `reset` in your implementation?

*Answer:* The best of both worlds would be to give the user possibility to initialize the library with initial sizes,
but if the user did not, we would still use the default ones (start from 1, grow to whenever necessary).

*Implementation:* See this [commit](https://github.com/asankov/the-practice-of-programming/commit/e6b9cb4315c5b184011fe6a80eb44c3d6699f690).

#### Exercise 4-4
Design and implement a library for creating CSV-formatted data. The simplest version might take an array of strings
and print them with quotes and commas. A more sophisticated version might use a format string analogous to `printf`.
Look at Chapter 9 for some suggestions on notation.

*Answer:* I build more like a prototype than a real library, but it is what it is.

The interface consists of only method:
```c
void generate_csv(FILE *fn)
```
this reads from `fn`, until `EOF` and prints a word everytime it encounters `" "`. It has no notion of new lines, and multiple columns, but hey, it's just a prototype.

For the interface see [`generate_csv.h`](generate_csv.h).

For the implementation see [`generate_csv.c`](generate_csv.h).
