## Chapter 3: Design and Implementation

### 3.3 Generating Output
**Summary:** Let's write some more [code](output.c)!

### Exercise 3-1
The algorithm for selecting a random item from a list of unknown length depends on having a good random number generator.
Design and carry out experiments to determine how weel the method works in practice.

*Answer:* Running the program multiple times always produced the same output, although there are prefixes with more than
one suffix. This means that either the random function is not fully random, or the algorithm is broken.

After adding a seed, based on current time in [this commit](https://github.com/asankov/the-practice-of-programming/commit/bf10c68f853ae3997fd445dc169443297a707fb8) the results started to vary, which
means that the problem was the random number generator.

### Exercise 3-2
If each input word is stored in a second hash table, the text is only stored once, which should save space.
Measure some documents to estimate how much. This organization would allow us to compare pointers rather than strings
in the hash chains for prefixes, which should run faster. Implement this version and measure the change in speed
and memory consumption.

*Answer:* This change should make the program more memory efficient, because we would be storing every string just once.
*TODO: add implementation*

### Exercise 3-3
Remove the statements that place sentinel `NONWORD`s at the beginning and end of the data, and modify `generate`
so it starts and stops properly without them. Make sure it produces correct output for input with 0, 1, 2, 3 and 4 words.
Compare the implementation to the version using sentinels.

*Answer:* *TODO: add answer and implementation*