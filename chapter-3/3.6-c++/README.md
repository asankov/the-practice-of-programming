# Chapter 3: Design and Implementation

## Section 3.6 C++

**Summary:** Let's rewrite these stuff in [C++](markov.cpp)!

### Exercise 3-5

The great strength of the STL is the ease with which one can experiment with different data structures.
Modify the C++ version of Markov to use various structures to represent the prefix, suffix list, and state table.
How does performance change for the different structures?

_Answer:_ Changes applied in this [commit](https://github.com/asankov/the-practice-of-programming/commit/d15f071648e617437256b644f4649299bca332d0).

The diff is very small, since we only reference these types once or twice.
TODO: measure performance between the two versions.

### Exercise 3-6

Write a C++ version that uses only classes and the `string` data type, but no other advanced library facilities.
Compare it in style and speed to the STL versions.

_Answer:_ I approached this incrementally, doing it type by type.
The changes are part of the following commits:

- `Suffixes` - `std::vector<std::string>` to `class Suffixes` that uses a Linked list under the hood - [`#bd84f3e`](https://github.com/asankov/the-practice-of-programming/commit/bd84f3e6112069e25f56e798d08384ea3d5aa50b)
- `State` - `std::map<Prefix, Suffixes>` to `class StateMap` that uses a hash map under the hood - [`#e84ba3d`](https://github.com/asankov/the-practice-of-programming/commit/e84ba3dd3f3f8fa7e9f831475b3e5499a129da47)
- `Prefix` - `std::deque<std::string>` to `class Prefix` that uses a simple array under the hood - [`#57f3f73`](https://github.com/asankov/the-practice-of-programming/commit/57f3f73a70cf9700a7559c694c8c7010afaca19d)

The first one was easy, the other two took more time, because there were more work that needed to be done for them.
The solution is really close to the C one, with the only difference that the details are encapsulated, behind the hoods of the classes.
But they are still there and the developers need to care for them.
In terms of the actual implementation that uses these structs and classes - not much changed, because I kept the contracts more or less the same.

Although it was fun implementing this stuff and hitting all the obstacles, in an actual world situation I would rarely choose the custom implementations over the library ones.
