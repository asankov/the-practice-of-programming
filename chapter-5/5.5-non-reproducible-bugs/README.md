# Chapter 5: Debugging

## Section 5.5 Non-reproducible Bugs

**Summary:** Something a bug is just hard to reproduce.

Not being able to reproduce the bug every time is nasty, but the fact itself gives you useful information -
the fault is probably not in the algorithm, but in something external to the program.

It could be an unitiliazed value that picks up random values, or a rogue seed. Remove everything random from the program in such case and make sure to initialized all variables to known values.

If adding debugging code removes the bug, this proprably means that there is something wrong with the memory allocation, which the additional codes removes.

When the program works for one person, but not for another debugging is hard, as you need to put yourself in the other person's shoes.
The reason prorably is in the difference in the environments - files present, environment variables, etc.

### Exercise 5-1

Write a version of `malloc` and `free` that can be used for debugging storage-management problems.
One approach is to check the entire workspace on each call of `malloc` and `free`;
another is to write logging information that can be processed by another program.
Either way, add markers to the beggining and end of each allocated block to detect overruns at either end.

_Answer:_ TODO
