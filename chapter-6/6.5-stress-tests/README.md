# Chapter 6: Testing

## Section 6.5 Stress Tests

**Summary:** Programs need to be tested with inputs, which are considered "not-possible", because a computer does not know what is possible and what not and can provide any input to your program.
For example, if we are working with files, we always need to test our program with empty files.
If we are working with text files, we need to test our program with binary files and vice-versa.

Many problems come because programs don't handle wrong inputs well.
This can cause crashes, but also overflows and potential security problems as well.

The Ariadne 5 rocket exploded on its maiden flight in June 1996, because the navigation code was inherited from Ariadne 4.
Ariadne 5 was faster, so it provided bigger values to some of the variables in this code.
Shortly after launch, the software tried to convert a 64-bit floating point number to a 16-bit integer, which generated an overflow.
The software detected the overflow, but the error handling was not correct.
The software just decided to shut down the entire subsystem, which led to the rocket going off course and exploding.

### Exercise 6-10

Try to create a file that will crash your favourite text editor, compiler or other program.

_Answer_: I think that a big enough file should be able to crash any editor.
