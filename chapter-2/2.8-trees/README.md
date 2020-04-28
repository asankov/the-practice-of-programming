## Chapter 2: Algorithms and Data Structures

### Chapter 2.8 Trees

#### Exercise 2.11.
Compare the performance of `lookup` and `nrlookup`. How expensive is recursion compared to iteration?

*Answer:*
Solution can be found at [`rec_vs_iter.c`](rec_vs_iter.c).

A simple test with 15 elements showed that the iterative function is always faster.
Output was something in the borders of:
```
Iterative function is faster.
Iterative function took 0 s, 236 ns
Recursive function took 0 s, 316 ns
```
This means that with this amount of data, the iterative function is ~33% faster than the recursive one.
However, these results are not to be taken as conclusive, because the amount of data we test it is really small,
and I suspect that the way we measure time is not entirely accurate as well.

#### Exercise 2.12.
Use in-order traversal to create a sort routine. What time complexity does it have? 
Under what conditions might it behave poorly? How does its performance compare to our quicksort and a library version?

*Answer:* The implementation can be found at [`sort.c`](sort.c).
The time complexity should be *O(log n)*, however, in the end, all elements need to be traversed, so that
they can be printed(written), so that leeds me to think the complexity would be *O(n)*.
The performance depends on the structure of the tree. For a properly structured tree it should always
perform in the same manner. 
TODO: execute a proper performance tests againts the list quicksort.

#### Exercise 2.13.
Devise and implement a set of tests for verifying that the tree routines are correct.

*Answer:* The solution can be found at [`tests.c`](tests.c). I went with the same appoarch as in Exercise 2-10.