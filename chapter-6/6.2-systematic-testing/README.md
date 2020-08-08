## Chapter 6: Testing

## Section 6.2 Systematic Testing
**Summary:** It's important to test systematically so you know what you are testing and what to expect.
### Test incrementally
Test as you write the code. Don't wait to write everything at test it at once. It's much harder and time consuming.
Instead, write small testable parts, test them in isolation, and when combine them, test that they work together as well.
### Test simple parts first
The incremental approach also applies to how we test features. We should first test the easy and most common parts.
Only when we are sure this is working, should we go on with the harder and less used parts of our program.

If we want to test a program that does binary search in an array of integers, this is the order of the test cases we have to execute:
- search an array with no elements
- search an array with one element and a trial value that is
    - less that the single entry of the arrat
    - equal to the single entry
    - greater than the single entry
- search an array with two elements and trial values that
    - check all five possible combinations
- check behaviour with duplicate elements in the array and trial values
    - less that the value in the array
    - equal to the value
    - greater than the value
- search an array with three elements as with two elements
- search an array with four elements as with two and three

This cases can be executed manually, but it is good if we write a test scaffold that will run the tests for us.
### Know what output to expect
It is important to know what are the expected results of the tests, otherwise we are wasting our time.
This is context specific and depends on what we are testing, but generally:
- we can have sample output to compare to the actual one
- we can test the inverse (encryption/decryption)
- we can validate that the output is within known boundaries
### Verify conservation properties
Conservation properties should be verified within a program.
For example, if we are testing a hash map the number of insertions, minus the number of deletions should be equal to the
number of elements within the hash map.
### Compare independent implementations
A good way of testing a program is comparing its output to another independent implementation of the same program.
If the outputs differ, then at least one of them is wrong. If they are the same - there is a good change both are right.
### Measure test coverage
The main idea of testing is that every statement of our program has been executed at least once.
That is why it is important to measure test coverage and to be sure that this coverage it as higher as possible.
It is hard to achieve 100% coverage, because there are always some "can't be reached" statements, and because by just varying the inputs it's hard to get to all parts of our program.

#### Exercise 6-3
Describe how you would test `freq`.

*Answer:* `freq` is a program that outputs the times each character is found in a files.
See [`freq.c`](freq.c)
I would start by defining test files and the expected output for each of them.
Then I would run the program on the files and compare the input to the expected one.

### Exercise 6-4
Design and implement a version of `freq` that measures the frequencies of other types of data values, such as 32-bit integers or floating-point numbers.
Can you make one version of the program handle a variety of types elegantly?

*Answer:* The desing of the program will be similar to the one we have now. The difference would be in reading the input.
When doing so we would need to handle the case where the char is a number and read until a delimiter is found.
Then parse the number and increment its value in the character counter store.
TODO: implementation
