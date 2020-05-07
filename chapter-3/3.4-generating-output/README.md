## Chapter 3: Design and Implementation

### 3.3 Generating Output
**Summary:** Let's write some more [code](output.c)!

#### Exercise 3-1
The algorithm for selecting a random item from a list of unknown length depends on having a good random number generator.
Design and carry out experiments to determine how weel the method works in practice.

*Answer:* Running the program multiple times always produced the same output, although there are prefixes with more than
one suffix. This means that either the random function is not fully random, or the algorithm is broken.
