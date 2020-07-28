## Chapter 6: Testing

## Section 6.1 Test as You Write the Code
**Summary:** The earlier a problem is found, the better.
If we test our code as we are writing it, we may catch some bugs early and we have at least one test run before the code has even been compiled.
Finding and fixing the bugs while writing the code will save us the time to troubleshoot later and fix bugs in an already working and deployed system.
### Test code at its boundaries
One approach is to test small pieces of code at their boundary conditions.
This include `for` or `while` loops, conditional statements, etc.
Very often the bug includes at the bondary condition. When the input is empty, full, only one, etc.
If our code works for the boundary inputs it will probably work for the normal ones as well.
Boundary condition checking is effective for finding off-by-one errors. It becomes second nature with time and practice.
It helps eliminate some bugs, but not all of them.
### Test pre- and post-conditions
Verify that the code works for input which do not make sense. Basically, this means to validate your inputs
and return a sensible value (`0`, `[]`, `NULL`, etc.), even if the inputs are non-sensible.
Bogus inputs should not be ignored as they may lead to ugly crashed down the road.
### Use assertions
Use assertions to validate your inputs. C/C++ provide an assertion facility in `<assert.h>` that lets you do:
```c
assert(n > 0)
```
If that fails, the program will abort with a useful message, pointing at the callee (not the called function itself).
This will help us identify who is at fault.
However, because it aborts the program it is to be used only in extreme situations in which recovering is impossible.
### Program defensively
Check for conditions that can't or shoudln't happen, but might, because of an error somewhere else.
### Check error returns
Always check error returned from functions.
For example, `fprintf` or `fwrite` will return errors if there is unsufficient memory or another serious problem ocurred.

#### Exercise 6-1
Check out these examples at their boundaries, then fix them as necesary according to the principles of style
in Chapter 1 and the advice in this chapter.

- **6-1.a** See [`6-1-a.c`](6-1-a.c). We see that with faulty input, 0, -1, etc. we get multiple iterations before the value is returned. This is because we don't check if the input is valid. Solution in this [commit](https://github.com/asankov/the-practice-of-programming/commit/f349b9aec39b0dda02e75ab3b36541e3930a05a2)
- **6-1.b** See [`6-1-b.c`](6-1-b.c). Original solution results in the following when running `6-1-b.c`:
```
Test 1:
h
e
l
l
o
Test 2:

Test 3:

Test 4:
[1]    31362 segmentation fault  ./executable
```
We get a segmentation fault when `NULL` is passed to the `print` function, because we never check whether the passed value is legit. Also, we get a new line outputed when such is not part of the input (Test 3) - this is because we use `do-while` loop, instead of a `while` loop. Solution in this [commit](https://github.com/asankov/the-practice-of-programming/commit/076d8f06f381e551f516eebab7563fc36d540619)
- **6-1.c** This is meant to copy a string from source to destination. See [`6-1-c.c`](6-1-c.c) Original solution results in the following when running `6-1-c.c`:
```
[1]    40929 segmentation fault  ./executable
```
This is because we don't check if the input is NULL. Solution in this [commit](https://github.com/asankov/the-practice-of-programming/commit/d2ddb1169f251ccbfcfe92ff3dfedf6c0549685b)
- **6-1.d** Another string copy, which attempts to copy `n` characters from `s` to `t`.
The original solution produces this output when runnung `6-1-d.c`:
```
[1]    42710 segmentation fault  ./executable
```
This is because the function does not check whether the input is not `NULL`.
Solution in this [commit](https://github.com/asankov/the-practice-of-programming/commit/5824a5424f72c2479d65a8d8304d404437d1937d)
- **6-1.e** A numerical comparison. See [`6-1-e.c`](6-1-e.c). Running the origin solution results in:
```
1 is smaller than 2.
1 is greater than 0.
1 is smaller than 1.
```
This is because we don't handle the quality of the two numbers.
After applying the solution:
```
1 is smaller than 2.
1 is greater than 0.
1 is equal to 1.
```
See the solution in this [commit](https://github.com/asankov/the-practice-of-programming/commit/853b52f3998d978d1ff1fc524a85c82490bed629)
- **6-1.f** A character class test. See [`6-1-f.c`](6-1-f.c). Running the original solution resulted in:
```
A - first half of alphabet
Z - second half of alphabet
L - first half of alphabet
M - second half of alphabet
a - z - l - m - %
```
which means the program is working fine for upper-case letter, but not for lower-case.
The solution resulted in:
```
A - first half of alphabet
Z - second half of alphabet
L - first half of alphabet
M - second half of alphabet
a - first half of alphabet
z - second half of alphabet
l - first half of alphabet
m - second half of alphabet
```
See the solution in this [commit](https://github.com/asankov/the-practice-of-programming/commit/e464dd266dc63d0928374b91bae5bb7b515aeada)
#### Exercise 6-2
As we are writing this book in late 1998, [the Year 2000 problem](https://en.wikipedia.org/wiki/Year_2000_problem) looms as perhaps the biggest boundary condition problem ever.
- **6-2.a** What dates would you use to check whether a system is likely to work in the year 2000?
Supposing the tests are expensive to perform, in what order would you do your tests after trying January 1, 2000 itself?

*Answer:* The most obvious first choice is `January 1, 2000`. The next ones - maybe `January 2, 2000` is another good choice. The next one should be offset in a sensible way - by a number that corresponds with the number of bits that when added to the date go to the next boundary condition.
- **6-2.b** How would you test the standart function `ctime`, which returns a string representation of the date in this form:
```
Fri Dec 31 23:58:27 EST 1999\n\0
```
Suppose your program calls `ctime`. How would you write your code to defend againts flawed implementation?

*Answer:* Proper testing of the function can be done by pattern/regex matching. E.g. we can strip away the parts we don't care about and validate that we have a proper year, proper time (hour not bigger than 23, minutes and seconds not bigger than 59, etc.). We can defend our program from faulty implementation by checking the result of the function. The simplest check could be a `NULL` check. More comprehensive testing involves the kinds of tests described in the previous sentence.
- **6-2.c** Describe how you would test a calendar program that prints output like this:
```
    January 2000
  S  M Tu  W Th  F  S
                    1
  2  3  4  5  6  7  8
  9 10 11 12 13 14 15
 16 17 18 19 20 21 22
 23 24 25 26 27 28 29
 30 31
```
*Answer:* Firstly, we can validate that the month name is a valid one, comparing it to a list of all valid month names.
Secondly, we can validate the rows that says which day of the week it is, because that is always the same.
Finally, we can validate that all the numbers are in order.
