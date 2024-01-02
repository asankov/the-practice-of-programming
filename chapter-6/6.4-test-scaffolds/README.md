# Chapter 6: Testing

## Section 6.4 Test Scaffolds

**Summary:** Sometimes testing the whole program is not what you want.
Sometimes you want to test a small, isolated part of the program.
Ofter this boils down to calling a function with a given input, and checking the return result.
To do that, we need a proper scaffold and a testing matrix - given input, expected output.

### Exercise 6-6

Create the test scaffold for `memster` along the lines that we indicated.

### Exercise 6-7

Create tests for the rest of the `mem...` family.

### Exercise 6-8

Specify a testing regime for numerical routines like `sqrt`, `sin`, and so on, as found in `math.h`.
What values make sense? What independent checks can be performed?

### Exercise 6-9

Define mechanisms for testing the functions of the C `str...` family, like `strcmp`.
Some of these functions, especially tokenizers like `strtok` and `strcspn` are significantly more complicated than the `mem...` family,
so more sophisticated tests will be called for.
