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

TODO: implementations

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

TODO: implementations
