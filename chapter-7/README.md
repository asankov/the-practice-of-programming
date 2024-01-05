# Chapter 7: Performance

## Chapter Summary

In the past, performance was important, because computers were lacking memory and compute power.

Nowadays, performance is not that important in most cases.

We should only be optimizing parts of the code that we know are worth optimizing like bottlenecks.

## 7.1 A Bottleneck

This chapter tells the story of a bottleneck in an email gateways - the spam filter.

It tells how the problem was investigated, profiled and finally optimized.

### Exercise 7-1

A table that maps a single character to the set of patterns that begin with this character gives an order of magnitude improvement.
Implement a version of `isspam` that uses two characters as the index.
How much improvement does that lead to?
These are special cases of a data structure called a _trie_.
Most such data structures are based on trading space for time.

## 7.2 Timing and Profiling

### Automated timing measurements

Most systems have commands that time the execution of a program.
For Unix such command is `time`.

### Use a profiler

Profilers are important, because they show much time was spend in each part of the program (for example, how much time is spend in each function and how many times a function is called).

They can be crucial to understanding where the bottleneck is and who is the culprit.

### Concentrate on the hot spots

Optimize the most slow parts of the program first.

### Draw a picture

Some profilers can generate a visual overview of the performance of the program.
That can be used to easily understand the profile, or to compare the profiles of two versions of a program.

### Exercise 7-2

Whether or not your system has a `time` command, use `clock` or `getTime` to write a timing facility for your own use.
Compare its times to a wall clock.
How does other activity on the machine affect the timings?

_Answer:_ [Here](./7-2/main.go).

### Exercise 7-3

In the first profile, `strchr` was called 48,350,000 times and `strncmp` only 46,180,000.
Explain the difference.

## 7.3 Strategies for Speed

Some strategies for what to do when you need to optimize:

### Use a better algorithm or data structure

This can have a huge performance benefit, if we have initially chosen the wrong algorithm or data structure.

Sometimes changning the algorithm or the data structure includes trading memory for disk space.

### Enable compiler optimizations

Compilers can do some optimizations on behalf of the programmer to make the code run faster.

### Tune the code

Change the code in a way that will be more efficient.

### Don't optimiza what doesn't matter

Don't optimize parts of the code that are not bottlenecks, or that are not used enough for their speed to matter.

## 7.4 Tuning the Code

Some strategies for how to change the code to be more efficient:

### Collect common subexpressions

For example:

```c
sqrt(dx*dx + dy*dy) + (sqrt(dx*dx + dy*dy) > 0 ? ...)
```

can become:

```c
sqrtr = sqrt(dx*dx + dy*dy)
sqrtr + (sqrtr > 0 ? ...)
```

This removes one computation.

Another example:

```c
for (i = 0; i < nstarting[c]; i++) {...}
```

becomes:

```c
n = nstarting[c]
for (i = 0; i < n; i++) {...}
```

This changes the times we lookup the `c` element of the `nstarting` array to just one, instead of each time we loop.

### Replace expensive operations by cheap ones

If we have a function that is too expensive, we can look for a way to re-write it or replace it with something else.

### Unroll or eliminate loops

Loops add overhead to the code.
We can look for ways to avoid them.

For example:

```c
for (i = 0; i < 3; i++)
    a[i] = b[i] + c[i];
```

can become:

```c
a[1] = b[1] + c[1];
a[2] = b[2] + c[2];
a[3] = b[3] + c[3];
```

### Cache frequently-used values

Caching can improve performance, because it replaces computation with a lookup.

When we call a computational-function we can store the computated result into a cache, and if we call it again with the same value we can get the result from the cache instead of precomputing it again.

This consumes more memory, but it more computation-efficient.

### Write a special-purpose allocator

Sometimes allocations can slow down the program.

We can write our own allocator that does multiple allocations at ones and caches the values.
When we call our allocator again, it will return an already allocated memory, instead of making another allocation.

This again trades speed for memory.

### Buffer input and output

Batch IO operations, instead of performing them right away.

### Handle special cases separately

Have different logic for special cases (e.g. too big computations, or too big memory allocations).

### Precompute results

Similar to caching frequently-used values, we can cache some results, we know there is a high change we will use.

For example, if we write a `sin` or `cos` function, we can precompute the results from `0` to `360` instead of calculating them each time.

### Use approximate values

If we can get away with less precission, we can approximate special inputs to known ones.

For example, we can this for the `sin` and `cos` functions where we approximate the input to the known 0-360 values.

### Rewrite in a lower-level languages

Languages like C and C++ are more efficient that Java an Python.

### Exercise 7-4

One way to make a function like `memset` run faster is to have it write in word-sized chunks instead of byte-sized; this is likely to match the hardware better and might reduce the loop overhead by a factor of four or eight.
The downside is that there are now a variety of end effects to deal with if the target is not aligned on a word boundary and if the length is not a multiple of the word size.
Write a version of `memset` that does this optimization.
Compare its performance to the existing library version and to a straightforward byte-at-a-time loop.

### Exercise 7-5

Write a memory allocator `smalloc` for C strings that uses a special-purpose allocator for small strings but calls `malloc` directly for large ones.
You will need to define a struct to represent the strings in either case.
How do you decide where to switch from calling `smalloc` to `malloc`?

## 7.5 Space Efficiency

Some strategies for how to be more space-efficient:

### Save space by using the smallest possible data type

For example, replacing a `double` with a `float`.

### Don't store what you can easily recompute

By NOT storing values that can be easily recomputed we can save space by using more compute power.

## 7.6 Estimation

Estimate the cost of the operations you do in the code.

Some strategies for how to change the code to be more efficient:

Some strategies for how to change the code to be more efficient:

### Exercise 7-6

Create a set of tests for estimating the costs of basic operations for computers and compilers near you, and investigate similarities and differences in per-formance.

### Exercise 7-7

Create a cost model for higher-level operations in C++. Among the features that might be included are construction, copying, and deletion of class objects; member function calls; virtual functions; inline functions; the iostream library; the STL. This exercise is open-ended, so concentrate on a small set of representative operations. •

### Exercise 7-8

Repeat the previous exercise for Java.

## 7.7 Summary

Performance optimizations can only be done, when it is obvious that performance improvements are needed.

Choosing the right algorithm and data structure for the code is the most important thing for the performance of the code.
Most of the time, just doing that will be all that's needed for the code to perform well.

For special cases, there are more optimization strategies.

Sometimes we care about compute optimizations and we trade memory for compute power, sometimes it's the vice versa - we care about memory efficiency and we trade compute for memory.

## Supplementary Reading

- Software - Practice and Experience
- Programming Pearls by Jon Bentley
- More Programming Pearls by Jon Bentley
- Inner Loops by Rick Booth
- Computer Organization and Design: The Hardware/Software Interface by John Hennesy and David Patterson
