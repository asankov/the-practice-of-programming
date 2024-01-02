# Chapter 2: Algorithms and Data Structures

## 2.6 Growing Arrays

### Exercise 2.5

In the code above, `delname` doesn't call `realloc` to return the memory freed by the deletion.
Is this worthwhile? How would you decide whether to do so?

_Answer:_ Although not calling `realloc` when deleting a memory could become a nasty memory leak,
I think this can be fine when working with small amounts of data. However, if this data grows and there are many
insert and delete operations, then this memory leak could cause problems, and in this case it's better to
free the memory we are not using.

### Exercise 2.6

Implement the necessary changes to `addname` and `delname` to delete items by marking deleted items as unused. How isolated is the rest of the program from this change.

_Answer:_ The implementation can be found in `growing_arrays.c`, namely the `addname_marked` and `delname_marked` functions.
As for the second question, the other part of the program is just a called for these functions and thus the way we delete and add elements is just an implementational detail, for which the other parts ot he program should not care.
Provided that the interface is the same (which it is), the other parts of the program are well isolated from this change.
