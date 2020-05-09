## Chapter 3: Design and Implementation

### Section 3.6 C++
**Summary:** Let's rewrite these stuff in [C++](markov.cpp)!

#### Exercise 3-5
The great strength of the STL is the ease with which one can experiment with different data structures.
Modify the C++ version of Markov to use various structures to represent the prefix, suffix list, and state table.
How does performance change for the different structures?

*Answer:* Changes applied in this [commit](https://github.com/asankov/the-practice-of-programming/commit/d15f071648e617437256b644f4649299bca332d0).

The diff is very small, since we only reference these types once or twice.
TODO: measure performance between the two versions.
