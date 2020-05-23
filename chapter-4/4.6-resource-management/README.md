## Chapter 4: Interfaces

### Section 4.6 Resource Management
**Summary:** Getting resource management right is vital when it comes to designing interfaces and libraries. The questions that stand are of the sort:
- who owns the memory used by both the program and the library?
- who is responsible for cleaning up unused data?
- who is responsible for handling data races?

These problems are exposed in some of the C library functions like `strtok`. In OOP languages like C++ and Java objects are a good mechanics
for solving them, because they provide encapsulation. C++ has destructors in which you can define cleanup logic, for when after an instance is not needed anymore.
Java, on the other hand, has Garbage collector, which cleans a lot of stuff for you.

Our problems become even more when we are in a multi-threaded environment. In such, it is vital that we don't use global variables, and our code shares nothing,
except the interfaces. Other mechanisms that help are mutexed, locks and synchronized blocks.

