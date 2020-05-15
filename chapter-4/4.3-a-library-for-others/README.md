## Chapter 4: Interfaces

### Section 4.3 A Library For Others
**Summary:** In this chapter we will build on the knowledge we gained writing the prototype and will build a full-fledged
library to be used by others.

The library consists of a [header file](csv.h), where the interfaces lives
and a [source file](csv.c), where the implementation lives. The consumers of the library will import the header file,
which will reference the compiled implementation.