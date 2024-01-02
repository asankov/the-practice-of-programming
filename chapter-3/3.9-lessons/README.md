# Chapter 3: Design and Implementation

## Section 3.9 Lessons

**Summary:** The first thing to designing a program is the data and the data structures about it. These foundations then
can be implemented in different ways with different languages, but they will more or less be the same.
Using libraries and high-level programming language can help us speed up developement, but comes at a cost of giving up
complete control of what you program does, and not knowing what happens under the hood. This is a trade-off that needs to be considered.
Finally, writing production-ready code involves iteration and experimentation.

### Exercise 3-8

We have seen versions of the Markov program in a wide variaty of languages, including Scheme, Tcl, Prolog, Python, Generic Java, ML and Haskell;
each presents its own challenges and advantages. Implement the program in your favourite language and compare its general flavor and performance.

_Answer:_ Finally some [Golang](golang/main/main.go)! 🎉

Golang, being based on C++ means that the solution looks very much like the initial C++ solution that used `std::vector`, `std::queue`, etc. For key of the map, I had to use the array of string, not the wrapping `Prefix` struct, because
Golang does not like very much custom types as map keys.

The other parts of the solution were pretty straight-forward and similar to what we have already done for the other languages.
