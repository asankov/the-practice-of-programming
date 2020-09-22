## Chapter 4: Interfaces

### Section 4.4 A C++ Implementation
**Summary:** In this chapter we will implement the same library in C++.

See the implementation in [`csv.cpp`](csv.cpp)

### Exercise 4-5
Enhance the C++ implementation to overload subscripting with `operator[]` so that fields can be accesses as `csv[i]`.

*Answer:* Implemented directly in [`csv.cpp`](csv.cpp). See this [commit](https://github.com/asankov/the-practice-of-programming/commit/59a3bd15e0af3090a963603217589258a8c45b5a)

### Exercise 4-6
Write a Java version of the CSV library, then compare the three implementations for clarity, robustness and speed.

*Answer:* TODO: implementation

### Exercise 4-7
Repackage the C++ version of the CSV code as an STL iterator.

*Answer:* TODO: implementation

### Exercise 4-8
The C++ version permits multiple independent `Csv` instances to operate concurrently without interfering,
a benefit of encapsulating all the state in an object that can be instantiated multiple times.
Modify the C version to achieve the same effect by replacing the global data structures with structures that are
allocated and initialized by an explicit `csvnew` function.

*Answer:* TODO: implementation
